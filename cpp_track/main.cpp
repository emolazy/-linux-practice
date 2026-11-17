#include <iostream>

// Это наше "заклинание". Оно принимает два ингредиента (x и y) и возвращает результат.
int multiply(int x, int y) {
    return (x * y);
    // ТВОЯ ЗАДАЧА: напиши здесь слово return и операцию умножения x на y
    // Подсказка: return x * y;
    
}
int main() {
    int ing1, ing2; // Количества двух ингредиентов

    std::cout << "=== АЛХИМИЧЕСКИЙ КОТЕЛ ===" << std::endl;
    std::cout << "Введите количество первого ингредиента: ";
    std::cin >> ing1;
    std::cout << "Введите количество второго ингредиента: ";
    std::cin >> ing2;

    // ТВОЯ ЗАДАЧА: Вызови функцию multiply и сохрани результат в переменную result
    // Подсказка: int result = multiply(ing1, ing2);
    
    int result = multiply(ing1, ing2);
    std::cout << "Ваше зелье готово! Итоговая сила: " << result << std::endl;

    return 0;
}