import requests
import logging
from pathlib import Path
from datetime import datetime

# Настройка логирования (запись в файл)
log_file = Path("checker.log")
logging.basicConfig(
    filename=log_file,
    level=logging.INFO,
    format="%(asctime)s - %(levelname)s - %(message)s",
    encoding="utf-8"
)

def check_url(url):
    """Проверяет доступность URL и пишет результат в лог."""
    try:
        response = requests.get(url, timeout=5)
        if response.status_code == 200:
            message = f"УСПЕХ: {url} доступен (Код: 200)"
            logging.info(message)
            print(message)
        else:
            message = f"ВНИМАНИЕ: {url} вернул код {response.status_code}"
            logging.warning(message)
            print(message)
    except requests.exceptions.RequestException as e:
        message = f"ОШИБКА: {url} недоступен. Причина: {e}"
        logging.error(message)
        print(message)

if __name__ == "__main__":
    # Проверяем пару сайтов
    urls_to_check = ["https://google.com", "https://github.com", "https://this-site-does-not-exist-12345.com"]
    
    for url in urls_to_check:
        check_url(url)
    
    print(f"\nРезультаты также записаны в файл: {log_file.absolute()}")