import requests
import json

# Метод GET. Вызываем API GitHub для получения информации о пользователе
url = "https://api.github.com/users/torvalds" # Линус Торвальдс
response = requests.get(url)

# 1. Проверяем КОД ОТВЕТА (Status Code)
print(f"Код ответа: {response.status_code}") # Должно быть 200 (OK)

# 2. Работаем с HEADERS (заголовками)
print(f"Тип данных от сервера: {response.headers.get('Content-Type')}") 

# 3. Парсим JSON
if response.status_code == 200:
    data = response.json() # Превращаем JSON-строку в Python-словарь
    # Выводим нужные нам поля
    print(f"Имя: {data['name']}")
    print(f"Компания: {data['company']}")
    print(f"Публичных репозиториев: {data['public_repos']}")
else:
    print("Ошибка при запросе к API")