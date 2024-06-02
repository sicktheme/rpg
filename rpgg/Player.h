#pragma once
#include <iostream>
#include <map>
#include <string>

class Player {
public:
	enum PWeapons {pistol, rifle, katana, MAX_WEAPONS};
	enum PClasses {murderer, assassin, silent, MAX_CLASSES};

	friend std::ostream& operator << (std::ostream& out, const PWeapons& weapons) {
		switch (weapons) {
		case pistol: return (out << "Pistol");
		case rifle: return (out << "Rifle");
		case katana: return (out << "Katana");
		}
	}

	friend std::ostream& operator << (std::ostream& out, const PClasses& classes) {
		switch (classes) {
		case murderer: return (out << "Murderer");
		case assassin: return (out << "Assassin");
		case silent: return (out << "Silent");
		}
	}

	Player();

	int getHp() const;
	int getDmg() const;
	uint32_t getAge() const;
	uint64_t getGold() const;
	std::string getName() const;
	PClasses getClass() const;
	PWeapons getWeapon() const;
	size_t getWin() const;
	size_t getLoose() const;

	void setHp(int hp);
	void setDmg(uint32_t);
	void setAge(uint32_t age);
	void setGold(uint64_t gold);
	void setName(std::string& name);
	void setClass(PClasses classes);
	void setWeapon(PWeapons weapon);
	void setWin(size_t win);
	void setLoose(size_t loose);

	void recDmg(uint32_t dmg);
	void recGold(uint64_t gold);

	void addGold(uint64_t gold);
	void addWin();
	void addLoose();
	void addDmg(int dmg);
	void addHp(int hp);

	void pickWeapon(std::string& pick);

	void printStats();

	~Player();

private:
	int m_hp = 100;
	uint32_t m_dmg = 0;
	uint32_t m_age = 0;
	uint64_t m_gold = 10;
	std::string m_name = " ";
	size_t m_win = 0;
	size_t m_loose = 0;
	PClasses m_class;
	PWeapons m_gunType;
	std::map<std::string, int> m_weapon;
};