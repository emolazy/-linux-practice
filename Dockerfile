# 1. Базовый образ (откуда берем Python)
FROM python:3.11-slim

# 2. Рабочая директория внутри контейнера
WORKDIR /app

# 3. Копируем наш код и файл с зависимостями в контейнер
COPY api_test.py .
RUN pip install requests

# 4. Команда, которая запустится при старте контейнера
CMD ["python", "api_test.py"]