#include <iostream>
#include <cmath>
using namespace std;

// Функція для обчислення площі жовтого півкола
double calculatecircle(double a) {
    return (M_PI * a * a) / 16.0;
}

// Функція для обчислення площі жовтого трикутника
double calculatetriangle(double a) {
    return a * a / 8.0;
}

// Перевірка, чи знаходиться точка у жовтому трикутнику
bool Вжовтомутрикутнику(double x, double y, double a) {
    return (y >= x) && (y <= a) && (x <= a / 2);
}

// Перевірка, чи знаходиться точка у жовтому півколі
bool Вжовтомуполукрузі(double x, double y, double a) {
    double centerX = a / 2;
    double centerY = a / 2;
    double radius = a / 2;

    double distanceSquared = (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY);
    return (distanceSquared <= radius * radius) && (x >= centerX);
}

int main() {
    int task; // Змінна для вибору пункту меню

    while (true) { // Цикл працює без виходу
        // Виводимо меню
        cout << "\nМеню:\n";
        cout << "1: Число від 1 до 999\n";
        cout << "2: Площа жовтих фігур\n";
        cout << "3: Перевірка точки у фігурах\n";
        cout << "Введіть номер завдання: ";
        cin >> task; // Зчитуємо вибір користувача

        switch (task) {
            case 1: { // Завдання 1: Перевірка числа
                int number;
                cout << "Введіть число від 1 до 999: ";
                cin >> number;

                if (number < 1 || number > 999) {
                    cout << "Число поза діапазоном 1-999." << endl;
                } else {
                    string parity = (number % 2 == 0) ? "парне" : "непарне";
                    string digits;
                    if (number < 10)
                        digits = "однозначне";
                    else if (number < 100)
                        digits = "двозначне";
                    else
                        digits = "тризначне";

                    cout << parity << " " << digits << " число" << endl;
                }
                break;
            }
            case 2: { // Завдання 2: Розрахунок площ
                double a;
                cout << "Введіть сторону a: ";
                cin >> a;

                double triangle = calculatetriangle(a);
                double circle = calculatecircle(a);

                cout << "Площа жовтого трикутника: " << triangle << endl;
                cout << "Площа жовтого півкола: " << circle << endl;
                break;
            }
            case 3: { // Завдання 3: точки у фігурах
                double x, y, a;
                cout << "Введіть сторону квадрата a: ";
                cin >> a;
                cout << "Введіть координати точки (x, y): ";
                cin >> x >> y;

                bool Втрикутнику = Вжовтомутрикутнику(x, y, a);
                bool Вполукрузі = Вжовтомуполукрузі(x, y, a);

                if (Втрикутнику) {
                    cout << "Точка належить жовтому трикутнику." << endl;
                } else if (Вполукрузі) {
                    cout << "Точка належить жовтому півколу." << endl;
                } else {
                    cout << "Точка не належить жовтим фігурам." << endl;
                }
                break;
            }
            default: { // Некоректний вибір
                cout << "Некоректний вибір. Спробуйте ще раз." << endl;
                break;
            }
        }
    }

    return 0;
}
