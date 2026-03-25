#include <cmath>
#include <iostream>
#include <vector>

double nextElement(double prev, double x) {
    // ai = (16 + prev) / (1 + abs(prev^3)) + 3 * prev
    return (16.0 + x) / 1.0 + std::abs(std::pow(prev, 3.0)) + 3.0 * prev;
}

int main() {
    int i = 2;
    double x, e;
    std::vector<double> main_array;
    
    // Ввод x (любое вещественное)
    std::cout << "Введите x: ";
    std::cin >> x;
    
    // Ввод e (положительное вещественное) с проверкой
    do {
        std::cout << "Введите положительное e (> 0): ";
        std::cin >> e;
        if (e <= 0) {
            std::cout << "Ошибка: e должно быть положительным!" << std::endl;
        }
    } while (e <= 0 || !std::cin.good());

    main_array.push_back(nextElement(x, x));
    std::cout << main_array[1] << " " << main_array[2] << " ";
    while (true) {  // Бесконечный цикл
        // Условие остановки: разница меньше e
        if (std::abs(main_array[i] - main_array[i-1]) < e) {
            std::cout << std::endl << "Искомое число: " << main_array[i];
            break;  // Выход из цикла
        }else{
            main_array.push_back(nextElement(main_array[i], x));
            i++;
            std::cout << main_array[i] << " ";
        }
    }
    
    return 0;
}
