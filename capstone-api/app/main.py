from fastapi import FastAPI
from . import models
from .database import engine
from .routers import checks

# Создаем таблицы (Alembic тоже это делает, но пусть будет для подстраховки)
models.Base.metadata.create_all(bind=engine)

app = FastAPI(title="My Capstone API", version="1.0.0")

# Подключаем наш роутер
app.include_router(checks.router)

@app.get("/")
def read_root():
    return {"message": "Hello, DevOps!"}

@app.get("/health")
def health_check():
    return {"status": "ok"}