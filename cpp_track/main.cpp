#include <iostream>
#include <vector>
#include <string>

// 1. Создаем структуру задачи (по сути, это класс для хранения данных)
struct Task {
    int id;
    std::string description;
    bool isDone;
};

// Функция для вывода меню
void showMenu() {
    std::cout << "\n=== МЕНЕДЖЕР ЗАДАЧ ===" << std::endl;
    std::cout << "1. Добавить задачу" << std::endl;
    std::cout << "2. Показать все задачи" << std::endl;
    std::cout << "3. Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

int main() {
    std::vector<Task> tasks; // Наш "умный массив" для хранения всех задач
    int nextId = 1;          // Счетчик для ID новых задач
    int choice = 0;          // Переменная для выбора пункта меню

    // Главный цикл программы. Работает, пока пользователь не выберет 3
    while (choice != 3) {
        showMenu();
        std::cin >> choice;

        if (choice == 1) {
            // ДОБАВЛЕНИЕ ЗАДАЧИ
            std::cin.ignore(); // Очищаем буфер, чтобы getline работал нормально
            std::string desc;
            std::cout << "Введите описание задачи: ";
            std::getline(std::cin, desc); // Читаем целую строку (с пробелами)

            Task newTask;
            newTask.id = nextId;
            newTask.description = desc;
            newTask.isDone = false;

            tasks.push_back(newTask); // Добавляем задачу в конец вектора
            nextId++;
            std::cout << "Задача успешно добавлена!" << std::endl;

        } else if (choice == 2) {
            // ПРОСМОТР ЗАДАЧ
            std::cout << "\n--- СПИСОК ЗАДАЧ ---" << std::endl;
            if (tasks.empty()) {
                std::cout << "Список пуст. Добавьте первую задачу!" << std::endl;
            } else {
                for (int i = 0; i < tasks.size(); i++) {
                    std::cout << "[" << tasks[i].id << "] " << tasks[i].description;
                    if (tasks[i].isDone) {
                        std::cout << " (ВЫПОЛНЕНО)";
                    } else {
                        std::cout << " (В процессе)";
                    }
                    std::cout << std::endl;
                }
            }
        } else if (choice == 3) {
            std::cout << "Выход из программы. До встречи!" << std::endl;
        } else {
            std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
        }
    }

    return 0;
}