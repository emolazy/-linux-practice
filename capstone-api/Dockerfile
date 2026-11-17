FROM python:3.11-slim

WORKDIR /app

# 1. Создаем обычного пользователя (не root)
RUN useradd -m appuser

COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY . .

# 2. Даем этому пользователю права на папку с приложением
RUN chown -R appuser:appuser /app

# 3. Переключаемся на этого пользователя
USER appuser

CMD ["uvicorn", "app.main:app", "--host", "0.0.0.0", "--port", "8000"]