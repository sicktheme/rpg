#include "Player.h"

Player::Player() {

}

int Player::getHp() const { return m_hp; }
int Player::getDmg() const { return m_dmg; }
uint32_t Player::getAge() const { return m_age; }
uint64_t Player::getGold() const { return m_gold; }
std::string Player::getName() const { return m_name; }
Player::PClasses Player::getClass() const { return m_class; }
Player::PWeapons Player::getWeapon() const { return m_gunType; }
size_t Player::getWin() const { return m_win; }
size_t Player::getLoose() const { return m_loose; }

void Player::setHp(int hp) { m_hp = hp; }
void Player::setDmg(uint32_t dmg) { m_dmg = dmg; }
void Player::setAge(uint32_t age) { m_age = age; }
void Player::setGold(uint64_t gold) { m_gold = gold; }
void Player::setName(std::string& name) { m_name = name; }
void Player::setWeapon(PWeapons weapon) { m_gunType = weapon; }
void Player::setWin(size_t win) { m_win = win; }
void Player::setLoose(size_t loose) { m_loose = loose; }
void Player::setClass(PClasses classes) { m_class = classes; }

void Player::recDmg(uint32_t dmg) { m_hp -= dmg; }
void Player::recGold(uint64_t gold) { m_gold -= gold; }

void Player::addGold(uint64_t gold) { m_gold += gold; }
void Player::addWin() { m_win++; }
void Player::addLoose() { m_loose++; }
void Player::addDmg(int dmg) { m_dmg += dmg; }
void Player::addHp(int hp) { m_hp += hp; }

void Player::pickWeapon(std::string& pick) {
	m_weapon["pistol"] = PWeapons::pistol;
	m_weapon["rifle"] = PWeapons::rifle;
	m_weapon["katana"] = PWeapons::katana;

	switch (m_weapon[pick]) {
	case pistol: setWeapon(PWeapons::pistol); setClass(PClasses::murderer); m_dmg = 23; break;
	case rifle: setWeapon(PWeapons::rifle), setClass(PClasses::assassin); m_dmg = 27; break;
	case katana: setWeapon(PWeapons::katana), setClass(PClasses::silent); m_dmg = 31; break;
	default: std::cout << "Error weapon" << '\n'; break;
	}
}

void Player::printStats() {
    std::cout << "+*********************************+\n"
        << "|**************Stats**************|\n"
        << "|Name: " << getName() << "        \t\t\t|\n"
        << "|Class: " << getClass() << "      \t\t|\n"
        << "|Weapon: " << getWeapon() << "    \t\t|\n"
        << "|Gold: " << getGold() << "        \t\t|\n"
        << "|Hp: " << getHp() << "            \t\t|\n"
        << "|Age: " << getAge() << "          \t\t|\n"
        << "|Damage: " << getDmg() << "       \t\t|\n"
        << "|Win: " << getWin() << "          \t\t|\n"
        << "|Loose: " << getLoose() << "      \t\t|\n"
        << "+*********************************+" << '\n';
}

Player::~Player() {

}