# Удалите старые строки client = TestClient(app) и импорт app
# Вместо этого используйте client, который придет из conftest.py

def test_read_root(client): # Добавьте client в аргументы
    response = client.get("/")
    assert response.status_code == 200

def test_health_check(client): # Добавьте client в аргументы
    response = client.get("/health")
    assert response.status_code == 200

def test_create_check(client): # Добавьте client в аргументы
    response = client.post("/checks/", json={"url": "https://test.com", "status": "200 OK"})
    assert response.status_code == 200

def test_create_check_invalid_data(client): # Добавьте client в аргументы
    response = client.post("/checks/", json={"url": "https://test.com"})
    assert response.status_code == 422