import logging
from pythonjsonlogger import jsonlogger
from fastapi import FastAPI, Depends
from sqlalchemy.orm import Session
from sqlalchemy import text
from prometheus_fastapi_instrumentator import Instrumentator # <-- НОВЫЙ ИМПОРТ

from .database import engine, SessionLocal
from .dependencies import get_db
from .routers import checks
from . import models

# ... (настройка логирования и создание app остаются без изменений) ...
logger = logging.getLogger()
logHandler = logging.StreamHandler()
formatter = jsonlogger.JsonFormatter()
logHandler.setFormatter(formatter)
logger.addHandler(logHandler)
logger.setLevel(logging.INFO)

app = FastAPI(title="My Capstone API", version="1.0.0")

# Подключаем инструментатор для сбора метрик Prometheus
Instrumentator().instrument(app).expose(app) # <-- НОВАЯ СТРОКА

app.include_router(checks.router)

# ... (эндпоинты / и /health остаются без изменений) ...