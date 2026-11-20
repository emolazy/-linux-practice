#include <iostream>
#include <string> // Обязательно для работы со строками!

int main() {
    // ТВОЯ ЗАДАЧА 1: Создай строковую переменную heroName и присвой ей имя твоего героя (например, "Воин").
    std::string heroName = "Vasya";

    // ТВОЯ ЗАДАЧА 2: Создай массив inventory типа int из 3 элементов. 
    // Например: золото (50), зелья (3), стрелы (100).
    int inventory[3] = {50, 3, 100};

    std::cout << "=== ИНВЕНТАРЬ ГЕРОЯ ===" << std::endl;
    std::cout << "Имя героя: " << heroName << std::endl;
    
    // ТВОЯ ЗАДАЧА 3: Выведи количество золота (элемент с индексом 0).
    // Задача 3 и 4: Выводим элементы по индексам (0, 1, 2)
    std::cout << "Золото: " << inventory[0] << std::endl;
    std::cout << "Зелья: " << inventory[1] << std::endl;
    std::cout << "Стрелы: " << inventory[2] << std::endl;
    
    // Бонус: Длина имени
    std::cout << "Длина имени героя: " << heroName.length() << " символов." << std::endl;
    
    return 0;
}