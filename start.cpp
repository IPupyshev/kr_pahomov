#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

double nextElement(double prev, double x) {
    return (16.0 + x) / (1.0 + std::abs(std::pow(prev, 3.0))) + 3.0 * prev;
}

void task1() {
    int i = 1;
    double x, e;
    std::vector<double> main_array;
    
    std::cout << "Input x: ";
    std::cin >> x;
    
    do {
        std::cout << "Input positive e (> 0): ";
        std::cin >> e;
        if (e <= 0) {
            std::cout << "Error: e should be positive\n";
        }
    } while (e <= 0 || !std::cin.good());
    
    main_array.push_back(x);
    main_array.push_back(nextElement(x, x));
    std::cout << main_array[0] << " " << main_array[1] << " ";
    
    while (true) {
        if (std::abs(main_array[i] - main_array[i-1]) < e) {
            std::cout << "\nFinded number: " << main_array[i] << std::endl;
            break;
        } else {
            main_array.push_back(nextElement(main_array[i], x));
            i++;
            std::cout << std::fixed << std::setprecision(2) << main_array[i] << " ";
        }
    }
}

void sort_array() {
    std::vector<double> arr;
    double num;
    
    std::cout << "Insert numbers (Enter after every, Ctrl+Z to end):\n";
    
    while (std::cin >> num) {
        arr.push_back(num);
    }
    
    if (std::cin.eof()) {
        std::cin.clear();
    }
    
    std::cout << "\nTotal elements: " << arr.size() << std::endl;
    
    int pos = 0, neg = 0, zero = 0;
    for (double x : arr) {
        if (x > 0) pos++;
        else if (x < 0) neg++;
        else zero++;
    }
    
    std::cout << "Positive: " << pos << ", Negative: " << neg << ", Zeroes: " << zero << std::endl;
    
    // ❌ БЫЛО std::min({pos, neg, zero})
    // ✅ СТАЛО ручное сравнение
    int min_count = pos;
    if (neg < min_count) min_count = neg;
    if (zero < min_count) min_count = zero;
    
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
    
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            double temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
    
    std::cout << "Result (" << arr.size() << " elements):\n";
    for (double x : arr) {
        std::cout << std::fixed << std::setprecision(2) << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    int choice;
    while (true) {
        std::cout << "\n1. Task 1\n2. Task 2\n3. End\nChoice: ";
        std::cin >> choice;
        
        if (choice == 1) {
            task1();
        } else if (choice == 2) {
            sort_array();
        } else if (choice == 3) {
            break;
        }
    }
    return 0;
}
