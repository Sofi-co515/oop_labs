#include <iostream>
int main() {
    int n;  
    std::cout << "Введите количество элементов в массиве: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Число элементов должно быть положительным!" << std::endl;
        return 1;
    }
    int* array = new int[n];
    std::cout << "Введите " << n << " целых чисел:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    std::cout << "Содержимое массива:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Элемент[" << i << "] = " << array[i] 
                  << ", Адрес: " << &array[i] 
                  << ", Расстояние от начала массива: " << (i * sizeof(int)) << " байт" << std::endl;
    }
    std::cout << "Адрес начала массива: " << array << std::endl;
    delete[] array;
    return 0;
}
