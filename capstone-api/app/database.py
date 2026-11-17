import os
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker, declarative_base

# Берем URL из переменной окружения (которую мы задали в docker-compose), 
# или используем локальную, если запускаем без Docker
SQLALCHEMY_DATABASE_URL = os.getenv(
    "DATABASE_URL", 
    "postgresql+psycopg2://user:password@localhost:5433/capstone_db"
)

engine = create_engine(SQLALCHEMY_DATABASE_URL)
SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)

# Вот та самая строчка, которую не мог найти Docker!
Base = declarative_base()