import logging
from pythonjsonlogger import jsonlogger
from fastapi import FastAPI, Depends
from sqlalchemy.orm import Session
from sqlalchemy import text
from prometheus_fastapi_instrumentator import Instrumentator

from .database import engine, SessionLocal
from .dependencies import get_db
from .routers import checks
from . import models

# 1. НАСТРОЙКА JSON-ЛОГИРОВАНИЯ
logger = logging.getLogger()
logHandler = logging.StreamHandler()
formatter = jsonlogger.JsonFormatter()
logHandler.setFormatter(formatter)
logger.addHandler(logHandler)
logger.setLevel(logging.INFO)

# 2. СОЗДАНИЕ ПРИЛОЖЕНИЯ
app = FastAPI(title="My Capstone API", version="1.0.0")

# Подключаем метрики Prometheus
Instrumentator().instrument(app).expose(app)

# Подключаем роутер для проверок (/checks/)
app.include_router(checks.router)

# 3. ЭНДПОИНТЫ (именно их не хватало!)
@app.get("/")
def read_root():
    logger.info("Запрошен корневой эндпоинт")
    return {"message": "Hello, DevOps!"}

@app.get("/health")
def health_check(db: Session = Depends(get_db)):
    try:
        db.execute(text("SELECT 1"))
        logger.info("Health check passed: DB is connected")
        return {"status": "ok", "database": "connected"}
    except Exception as e:
        logger.error(f"Health check failed: {e}")
        return {"status": "error", "database": "disconnected"}