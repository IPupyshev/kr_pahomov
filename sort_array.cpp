#include <iostream>
#include <vector>
#include <iomanip>

int sort_array() {
    std::vector<double> arr;
    double num;
    
    // Ввод массива неизвестной длины
    std::cout << "Введите числа (Enter после каждого, Ctrl+Z для окончания):\n";
    
    while (std::cin >> num) {
        arr.push_back(num);
    }
    
    if (std::cin.eof()) {
        std::cin.clear();
    }
    
    std::cout << "\n Введено элементов: " << arr.size() << std::endl;
    
    // Подсчет
    int pos = 0, neg = 0, zero = 0;
    for (double x : arr) {
        if (x > 0) pos++;
        else if (x < 0) neg++;
        else zero++;
    }
    
    std::cout << "Положительных: " << pos << ", Отрицательных: " << neg << ", Нулей: " << zero << std::endl;
    
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
    std::cout << "Результат (" << arr.size() << " элементов):\n";
    for (double x : arr) {
        std::cout << std::fixed << std::setprecision(2) << x << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
