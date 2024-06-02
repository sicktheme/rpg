#pragma once
#include <iostream>

class Monster {
public:
	enum MType {vampire, ghoul, dragon, MAX_MONSTERS};

	Monster(int,uint32_t,MType);
	~Monster();

	friend std::ostream& operator << (std::ostream& out, const MType& classes) {
		switch (classes) {
		case vampire: return (out << "Vampire");
		case ghoul: return (out << "Ghoul");
		case dragon: return (out << "Dragon");
		}
	}

	int getHp() const;
	uint32_t getDmg() const;
	MType getType() const;

	void setHp(int hp);
	void setDmg(uint32_t dmg);
	void setType(MType type);

	void recDmg(uint32_t dmg);

	void printStats();

	static Monster genMonst();

private:
	int m_hp;
	uint32_t m_dmg;
	MType m_type;
};