#include <iostream>
void addTen(int& num) {
    num = num + 10; // Берем текущее значение, прибавляем 10 и записываем обратно
}

int main() {
    int myVar = 5;
    
    std::cout << "До функции: " << myVar << std::endl; // Выведет 5
    
    addTen(myVar); // Вызываем функцию. Копия не создается, функция работает с myVar напрямую
    
    std::cout << "После функции: " << myVar << std::endl; // Выведет 15!
    
    return 0;
}