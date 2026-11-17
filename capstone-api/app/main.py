from fastapi import FastAPI
from . import models
from .routers import checks

app = FastAPI(title="My Capstone API", version="1.0.0")

# Подключаем наш роутер
app.include_router(checks.router)

@app.get("/")
def read_root():
    return {"message": "Hello, DevOps!"}

@app.get("/health")
def health_check():
    return {"status": "ok"}