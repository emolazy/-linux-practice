from sqlalchemy import Column, Integer, String
from .database import Base

class URLCheck(Base):
    __tablename__ = "url_checks"

    id = Column(Integer, primary_key=True, index=True)
    url = Column(String, index=True)
    status = Column(String)
