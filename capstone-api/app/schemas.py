from pydantic import BaseModel, ConfigDict

class URLCheckRequest(BaseModel):
    url: str
    status: str

class URLCheckResponse(URLCheckRequest):
    id: int

    # Новый, современный способ настройки (вместо class Config)
    model_config = ConfigDict(from_attributes=True)