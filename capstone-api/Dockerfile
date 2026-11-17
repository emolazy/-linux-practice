# --- Этап 1: Сборка (Builder) ---
FROM python:3.11-slim AS builder

WORKDIR /app

# Копируем зависимости и ставим их в отдельную папку
COPY requirements.txt .
RUN pip install --no-cache-dir --prefix=/install -r requirements.txt

# --- Этап 2: Финальный (Runtime) ---
FROM python:3.11-slim

WORKDIR /app

# Создаем безопасного пользователя
RUN useradd -m appuser

# Копируем установленные библиотеки из первого этапа
COPY --from=builder /install /usr/local

# Копируем код приложения
COPY . .

# 🚨 ФИКС: Удаляем уязвимые пакеты сборки (pip, setuptools, wheel) из системы.
# Нашему приложению они не нужны для работы!
RUN rm -rf /usr/local/lib/python3.11/site-packages/pip* \
           /usr/local/lib/python3.11/site-packages/setuptools* \
           /usr/local/lib/python3.11/site-packages/wheel* \
           /usr/local/lib/python3.11/site-packages/jaraco* || true

# Меняем владельца файлов и переключаемся на безопасного пользователя
RUN chown -R appuser:appuser /app
USER appuser

CMD ["uvicorn", "app.main:app", "--host", "0.0.0.0", "--port", "8000"]