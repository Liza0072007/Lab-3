#include <iostream>
#include <cmath>

// Перевіряє, чи знаходиться точка у жовтому трикутнику
bool Вжовтомутрикутнику(double x, double y, double a) {
    return (y >= x) && (y <= a) && (x <= a / 2);
}

// Перевіряє, чи точка належить жовтому півколу
bool Вжовтомуполукрузі(double x, double y, double a) {
    double centerX = a / 2; 
    double centerY = a / 2; 
    double radius = a / 2; 
    
    // Відстань від точки до центра кола в квадраті
    double distanceSquared = (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY);
    return (distanceSquared <= radius * radius) && (x >= centerX);
}

int main() {
    double x, y, a; // Змінні для введення
    std::cout << "Введіть сторону квадрата a: "; // Запит розміру квадрата
    std::cin >> a; // Зчитування сторони квадрата
    std::cout << "Введіть координати точки (x  y): "; // Запит координат точки
    std::cin >> x >> y; // Зчитування координат

    // Виклики функцій для перевірки розташування точки
    bool Втрикутнику = Вжовтомутрикутнику(x, y, a); 
    bool Вполукрузі = Вжовтомуполукрузі(x, y, a);   

    // Вивід результатів
    if (Втрикутнику) { 
        std::cout << "Точка належить жовтому трикутнику." << std::endl; 
    } else if (Вполукрузі) { 
        std::cout << "Точка належить жовтому  колу." << std::endl; 
    } else { 
        std::cout << "Точка не належить жовтим фігурам." << std::endl; 
    }

    return 0; // Завершення програми
}

