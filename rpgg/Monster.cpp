#include "Monster.h"

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Monster::Monster(int hp, uint32_t dmg, MType type) : m_hp(hp), m_dmg(dmg), m_type(type) {}

int Monster::getHp() const { return m_hp; }
uint32_t Monster::getDmg() const { return m_dmg; }
Monster::MType Monster::getType() const { return m_type; }

void Monster::setHp(int hp) { m_hp = hp; }
void Monster::setDmg(uint32_t dmg) { m_dmg = dmg; }
void Monster::setType(MType type) { m_type = type; }

void Monster::recDmg(uint32_t dmg) { m_hp -= dmg; }

void Monster::printStats() {
    std::cout << "+*********************************+\n"
        << "|**************Stats**************|\n"
        << "|Class: " << getType() << "      \t\t|\n"
        << "|Hp: " << getHp() << "            \t\t|\n"
        << "|Damage: " << getDmg() << "       \t\t|\n"
        << "+*********************************+" << '\n';
}

Monster Monster::genMonst() {
    int hp{ static_cast<int>(getRandomNumber(30,70)) };
    uint32_t dmg{ static_cast<uint32_t>(getRandomNumber(5,10)) };
    MType type{ static_cast<MType>(getRandomNumber(0,2)) };
    return Monster(hp, dmg, type);
}

Monster::~Monster() {}
