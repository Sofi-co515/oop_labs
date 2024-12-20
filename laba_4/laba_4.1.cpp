#include <iostream>
#include <stdexcept>
class Vehicle
{
public:
    virtual void info() const = 0;
    virtual ~Vehicle() = default;
};
// Классы, наследующие от Vehicle
class Bicycle : public Vehicle
{
public:
    void info() const override
    {
        std::cout << "Это велосипед." << std::endl;
    }
};
class Car : public Vehicle
{
public:
    void info() const override
    {
        std::cout << "Это автомобиль." << std::endl;
    }
};

class Truck : public Vehicle
{
public:
    void info() const override
    {
        std::cout << "Это грузовик." << std::endl;
    }
};
template <typename T>
class PointerArray
{
private:
    T **arr;
    size_t size;

public:
    PointerArray(size_t size) : size(size)
    {
        if (size == 0)
        {
            throw std::range_error("Размер массива должен быть положительным.");
        }
        arr = new T *[size];
        for (size_t i = 0; i < size; ++i)
        {
            arr[i] = nullptr;
        }
    }
    ~PointerArray()
    {
        for (size_t i = 0; i < size; ++i)
        {
            delete arr[i];
        }
        delete[] arr;
    }
    T *&operator[](size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Индекс вне диапазона");
        }
        return arr[index];
    }
    size_t getSize() const
    {
        return size;
    }
};
int main()
{
    try
    {
        const size_t arraySize = 3; // Размер массива
        PointerArray<Vehicle> vehicles(arraySize);
        // Создание объектов
        vehicles[0] = new Bicycle();
        vehicles[1] = new Car();
        vehicles[2] = new Truck();
        for (size_t i = 0; i < arraySize; ++i)
        {
            if (vehicles[i])
            {
                vehicles[i]->info();
            }
        }
        try
        {
            vehicles[3];
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
    }
    catch (const std::range_error &e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Общая ошибка: " << e.what() << std::endl;
    }
    return 0;
}
