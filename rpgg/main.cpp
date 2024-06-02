#include "Player.h"
#include "Monster.h"

bool arena(Player& player, Monster& monster) {
    std::cout << "Вы попали на арену. Победите монстра. За каждую победу над монстром вы получаете золото. После победы над монстром, появляется следующий\n";
    std::cout << "У вас есть выбор, сбежать или продолжать бой - (r)un, (h)it\n";
    std::string pick{ "" };
    do {
        std::cout << "> ";
        std::cin >> pick;
        if (pick == "h") {
            monster.recDmg(player.getDmg());
            player.recDmg(monster.getDmg());
            if (monster.getHp() < 0) {
                monster = Monster::genMonst();
                player.addGold(5);
                player.addWin();
                std::cout << "Монстер побежден. Победите нового.\n";
            }
            if (player.getHp() < 0) {
                player.setHp(0);
                player.addLoose();
                std::cout << "Ваше здоровье равно нулю. Вы проиграли\n";
                player.setGold(0);
                return false;
            }
            std::cout << "hp monster: " << monster.getHp() << '\n';
            std::cout << "hp player: " << player.getHp() << '\n';
        }
    } while (pick != "r" && pick != "run");

    std::cout << "Вы убежали с поля боя.\n";
    return false;
}

std::string shop() {
    //static PotionShop shop;
    std::cout << "Выберите зелье(hp - 20 gold, dmg - 25 gold): ";
    std::string pick;
    std::cin >> pick;
    return pick;
}

void menu() {
    std::cout << "****Menu****\n";
    std::cout << "1) Статистика персонажа\n";
    std::cout << "2) Магазин\n";
    std::cout << "3) Арена\n";
    std::cout << "4) Статистика монстра\n";
    std::cout << "5) Выход\n";
    std::cout << "> ";
}

int main()
{
    setlocale(LC_ALL, "ru");

    Player player;
    Monster monster = Monster::genMonst();

    std::cout << "Добро пожаловать в мир!" << '\n';
    std::cout << "Введите игровое прозвище: ";
    std::string name;
    getline(std::cin, name);
    player.setName(name);
    std::cout << "Введите свой игровой возраст: ";
    uint32_t age;
    std::cin >> age;
    player.setAge(age);
    std::cout << "Выберите оружие (pistol, rifle, katana). В зависимости от оружия, вам присвоится класс персонажа: ";
    std::string pickweapon;
    std::cin >> pickweapon;
    player.pickWeapon(pickweapon);

    std::string pickPotion;
    bool exit = false;
    int op = 0;

    while (!exit) {
        menu();
        std::cin >> op;
        system("cls");
        switch (op) {
        case 1:
            player.printStats();
            break;
        case 2:
            pickPotion = shop();
            if (pickPotion == "hp") {
                if (player.getGold() >= 20) {
                    player.recGold(20);
                    player.addHp(25);
                    std::cout << "Hp прибавлено. Ваше текущее hp: " << player.getHp() << '\n';
                }
                else {
                    std::cout << "Не хватает золота\n";
                }
            }
            if (pickPotion == "dmg") {
                if (player.getGold() >= 25) {
                    player.recGold(25);
                    player.addDmg(25);
                    std::cout << "Урон прибавлен. Ваш текущий dmg: " << player.getDmg() << '\n';
                }
                else {
                    std::cout << "Не хватает золота\n";
                }
            }
            break;
        case 3:
            arena(player, monster);
            system("cls");
            break;
        case 4:
            monster.printStats();
            break;
        case 5:
            exit = true;
            break;
        default:
            std::cout << "No operation\n";
            break;
        }
    }
}

