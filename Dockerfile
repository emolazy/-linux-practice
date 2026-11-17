# --- Этап 1: Сборка (Builder) ---
FROM python:3.11-slim AS builder

WORKDIR /app

# Обновляем pip в сборщике и ставим зависимости
RUN pip install --no-cache-dir --upgrade pip

COPY requirements.txt .
# Устанавливаем зависимости в отдельную папку
RUN pip install --no-cache-dir --prefix=/install -r requirements.txt

# --- Этап 2: Финальный (Runtime) ---
FROM python:3.11-slim

WORKDIR /app

# Создаем безопасного пользователя
RUN useradd -m appuser

# Копируем наши библиотеки из первого этапа
COPY --from=builder /install /usr/local

# Копируем код
COPY . .

# 🚨 ГЛАВНЫЙ ФИКС: Удаляем уязвимые pip и setuptools из финального образа. 
# Для запуска нашего приложения они не нужны!
RUN pip uninstall -y pip setuptools wheel || true

RUN chown -R appuser:appuser /app
USER appuser

CMD ["uvicorn", "app.main:app", "--host", "0.0.0.0", "--port", "8000"]