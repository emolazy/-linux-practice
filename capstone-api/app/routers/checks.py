from fastapi import APIRouter, Depends
from sqlalchemy.orm import Session
from .. import models, schemas
from ..dependencies import get_db

# Создаем роутер. Префикс /checks добавится ко всем путям в этом файле
router = APIRouter(prefix="/checks", tags=["URL Checks"])

@router.post("/", response_model=schemas.URLCheckResponse)
def create_check(check: schemas.URLCheckRequest, db: Session = Depends(get_db)):
    db_check = models.URLCheck(url=check.url, status=check.status)
    db.add(db_check)
    db.commit()
    db.refresh(db_check)
    return db_check

# Здесь в будущем мы добавим другие эндпоинты, например GET /checks (получить все проверки)
