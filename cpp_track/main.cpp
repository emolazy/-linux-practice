#include <iostream>
#include <string>

// 1. СОЗДАЕМ ЧЕРТЕЖ (Класс)
class Hero {
public:
    // Свойства (характеристики) героя
    std::string name;
    int hp;

    // Метод (действие): получить урон
    void takeDamage(int damage) {
        hp = hp - damage; // Вычитаем урон из текущего здоровья
        std::cout << name << " получил " << damage << " урона!" << std::endl;
    }

    // Метод (действие): показать статус
    void showStatus() {
        std::cout << "Герой: " << name << ", HP: " << hp << std::endl;
    }
};

int main() {
    // 2. СОЗДАЕМ ОБЪЕКТ (строим дом по чертежу)
    Hero hero1;

    // Задаем характеристики
    hero1.name = "Воин";
    hero1.hp = 100;

    // Показываем, что все ок
    hero1.showStatus(); // Выведет: Герой: Воин, HP: 100

    // Наносим урон
    hero1.takeDamage(30);

    // Показываем результат
    hero1.showStatus(); // Выведет: Герой: Воин, HP: 70

    return 0;
}