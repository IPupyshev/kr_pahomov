#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <limits>


double nextElement(double prev, double x) {
    // ai = (16 + prev) / (1 + abs(prev^3)) + 3 * prev
    return (16.0 + x) / (1.0 + std::abs(std::pow(prev, 3.0))) + 3.0 * prev;
}

void task1() {
    int i = 1;
    double x, e;
    std::vector<double> main_array;
    
    // Ввод x (любое вещественное)
    std::cout << "Input x: ";
    std::cin >> x;
    
    // Ввод e (положительное вещественное) с проверкой
    do {
        std::cout << "Input positive e (> 0): ";
        std::cin >> e;
        if (e <= 0) {
            std::cout << "Error: e should be positive" << std::endl;
        }
    } while (e <= 0 || !std::cin.good());
    main_array.push_back(x);
    main_array.push_back(nextElement(x, x));
    std::cout << main_array[0] << " " << main_array[1] << " ";
    while (true) {  // Бесконечный цикл
        // Условие остановки: разница меньше e
        if (std::abs(main_array[i] - main_array[i-1]) < e) {
            std::cout << std::endl << "Finded number: " << main_array[i];
            break;  // Выход из цикла
        }else{
            main_array.push_back(nextElement(main_array[i], x));
            i++;
            std::cout << std::fixed << std::setprecision(2) << main_array[i] << " ";
        }
    }
}


void sort_array() {
    std::vector<double> arr;
    double num;
    
    // Ввод массива неизвестной длины
    std::cout << "Insert numbers (Enter after every, Ctrl+Z to end):\n";
    
    while (std::cin >> num) {
        arr.push_back(num);
    }
    
    if (std::cin.eof()) {
        std::cin.clear();
    }
    
    std::cout << "\n Total elements: " << arr.size() << std::endl;
    
    // Подсчет
    int pos = 0, neg = 0, zero = 0;
    for (double x : arr) {
        if (x > 0) pos++;
        else if (x < 0) neg++;
        else zero++;
    }
    
    std::cout << "Positive: " << pos << ", Negative: " << neg << ", Zeroes: " << zero << std::endl;
    
    // Минимум
    int min_count = std::min({pos, neg, zero});
    
    // Удаление
    std::vector<double> result;
    for (double x : arr) {
        if ((x > 0 && pos == min_count) ||
            (x < 0 && neg == min_count) ||
            (x == 0 && zero == min_count)) {
            continue;
        }
        result.push_back(x);
    }
    
    arr = result;
    
    // СОРТИРОВКА ВЫБОРОМ БЕЗ std::swap
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Ручная замена БЕЗ std::swap
        if (min_idx != i) {
            double temp = arr[i];      // Временная переменная
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
    
    // Вывод
    std::cout << "Result is (" << arr.size() << " elements):\n";
    for (double x : arr) {
        std::cout << std::fixed << std::setprecision(2) << x << " ";
    }
    std::cout << std::endl;
}


int main() {
    int choice;
    while (true) {
        std::cout << "\n1. Task 1\n";
        std::cout << "2. Task 2\n";
        std::cout << "3. End\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        
        if (choice == 1) {
            task1();
        } else if (choice == 2) {
            sort_array();
        } else if (choice == 3) {
            break;  // Выход из цикла
        }
    }
    
    return 0;
}