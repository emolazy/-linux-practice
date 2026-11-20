# В Python НЕ НУЖНО указывать типы данных (как int или string)
name = "Иван"
age = 25
height = 1.85

# --- 1. Строки (аналог std::string) ---
# В Python можно легко форматировать строки через f-строки (очень удобно!)
print(f"Привет, меня зовут {name}. Мне {age} лет, мой рост {height} м.")

# --- 2. Условия (if / else) ---
# В Python НЕТ фигурных скобок {} и НЕТ круглых скобок для условия. 
# Вместо этого используются ОТСТУПЫ (обычно 4 пробела) и двоеточие в конце строки.
if age >= 18 and age < 65:
    print("Статус: Взрослый")
elif age >= 65:
    print("Статус: Пенсионер")
else:
    print("Статус: Ребенок")

# --- 3. Функции (аналог void/int func в C++) ---
# Пишется ключевое слово def, имя и аргументы. Типы указывать не обязательно.
def calculate_square(x, y):
    return x * y

result = calculate_square(5, 4)
print(f"Результат умножения: {result}")

# --- 4. Циклы (for/while) ---
# Цикл for в Python работает как "для каждого элемента в списке"
print("\nВыводим числа от 1 до 5 через цикл for:")
for i in range(1, 6): # range(1, 6) выдает числа от 1 до 5 (6 не включается)
    print(f"Шаг: {i}")

# Цикл while работает так же, как в C++
print("\nОбратный отсчет через while:")
countdown = 3
while countdown > 0:
    print(f"Осталось: {countdown}")
    countdown = countdown - 1 # или countdown -= 1
print("Поехали!")

def greet(name):
    # Твой код вывода здесь
    print(f"Привет, {name}! Ты готов к DevOps?")

greet("Ваня")