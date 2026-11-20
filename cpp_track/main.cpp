#include <iostream>
#include <fstream>   // Библиотека для работы с файлами
#include <string>
#include <stdexcept> // Библиотека для стандартных ошибок (исключений)

int main() {
    // --- БЛОК 1: ЗАПИСЬ В ФАЙЛ ---
    std::cout << "--- Попытка записи в файл ---" << std::endl;
    std::ofstream outFile("diary.txt"); // Создаем файл diary.txt

    if (outFile.is_open()) { // Проверяем, что файл открылся
        outFile << "Сегодня я выучил C++!" << std::endl;
        outFile << "Это вторая строчка дневника." << std::endl;
        outFile.close(); // Обязательно закрываем файл!
        std::cout << "Файл diary.txt успешно создан и записан." << std::endl;
    } else {
        std::cout << "Не удалось создать файл." << std::endl;
    }

    // --- БЛОК 2: ЧТЕНИЕ И ОБРАБОТКА ОШИБОК ---
    std::cout << "\n--- Попытка чтения секретного файла ---" << std::endl;
    
    try {
        // Пытаемся открыть файл, которого не существует
        std::ifstream inFile("secret.txt"); 

        // Если файл не открылся, мы "выбрасываем" ошибку
        if (!inFile.is_open()) {
            throw std::runtime_error("Файл secret.txt не найден на диске!");
        }

        // Этот код выполнится только если файл существует
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << "Прочитано: " << line << std::endl;
        }
        inFile.close();

    } catch (const std::exception& e) {
        // Сюда мы попадаем, если сработал throw
        std::cout << "ПОЙМАНА ОШИБКА: " << e.what() << std::endl;
        std::cout << "Программа не вылетела, она продолжает работу!" << std::endl;
    }

    std::cout << "\n--- Программа успешно завершена ---" << std::endl;
    return 0;
}