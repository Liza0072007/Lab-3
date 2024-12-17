#include <iostream>
#include <cmath>

// Обчислює площу трикутника, який вписаний у квадрат зі стороною a
double calculatetriangle(double a) {
    return a * a / 8.0;
}

// Обчислює площу півкола, яке вписане в квадрат зі стороною a
double calculatecircle(double a) {
    return (M_PI * a * a) / 16.0;
}

int main() {
    double a; // Змінна для введення сторони квадрата
    std::cout << "Введіть сторону a: "; // Виведення підказки для вводу
    std::cin >> a; // Зчитування значення сторони a
	
    // Обчислення площ
    double triangle = calculatetriangle(a); // Виклик функції для площі трикутника
    double circle = calculatecircle(a);    // Виклик функції для площі півкола

    // Виведення результатів
    std::cout << "Площа жовтого трикутника: " << triangle << std::endl;
    std::cout << "Площа жовтого  півкола: " << circle << std::endl;

    return 0; // Завершення програми
}
