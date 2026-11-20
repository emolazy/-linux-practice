#include <iostream>
#include <vector>  // Для умного массива
#include <map>     // Для словаря
#include <string>

int main() {
    // === 1. VECTOR (Умный массив) ===
    // Создаем список инвентаря. Тип данных в угловых скобках < >.
    std::vector<std::string> inventory;

    // Добавляем предметы (push_back - "втолкнуть в конец")
    inventory.push_back("Меч");
    inventory.push_back("Щит");
    inventory.push_back("Зелье");

    std::cout << "=== ИНВЕНТАРЬ (Vector) ===" << std::endl;
    std::cout << "Размер рюкзака: " << inventory.size() << std::endl;
    
    // Перебираем все элементы с помощью цикла for
    for (int i = 0; i < inventory.size(); i++) {
        std::cout << i + 1 << ". " << inventory[i] << std::endl;
    }

    // === 2. MAP (Словарь) ===
    // Создаем таблицу рекордов: имя (string) -> очки (int)
    std::map<std::string, int> scores;

    // Добавляем записи
    scores["Vasya"] = 100;
    scores["Petya"] = 250;
    scores["Masha"] = 150;
    scores["Pupa"] = 300;

    std::cout << "\n=== ТАБЛИЦА РЕКОРДОВ (Map) ===" << std::endl;
    
    // Выводим конкретное значение по ключу
    std::cout << "Очки Васи: " << scores["Vasya"] << std::endl;

    // Перебираем весь словарь
    // (Тут мы используем современный цикл for, который сам перебирает пары)
    for (const auto& pair : scores) {
        std::cout << "Игрок: " << pair.first << " | Очки: " << pair.second << std::endl;
    }

    return 0;
}