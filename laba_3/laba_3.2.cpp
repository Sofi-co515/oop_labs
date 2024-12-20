#include <iostream>
#include <vector>
#include <memory>
#include <type_traits>

class Part
{
protected:
    std::string name;
    Part(const std::string &n) : name(n) {}

public:
    virtual void display() const
    {
        std::cout << "Part: " << name << std::endl;
    }

    virtual ~Part() = default;
};

class Assembly : public Part
{
public:
    Assembly(const std::string &n) : Part(n) {}
    void display() const override
    {
        std::cout << "Assembly: " << name << std::endl;
    }
};

template <typename T>
void addPart(std::vector<std::shared_ptr<Part>> &storage, const std::string &name)
{
    static_assert(std::is_base_of<Part, T>::value, "T must be derived from Part");
    static_assert(!std::is_same<Part, T>::value, "Cannot create instances of base class Part");
    storage.push_back(std::make_shared<T>(name));
}

int main()
{
    std::vector<std::shared_ptr<Part>> storage;
    // Добавляем детали и сборки
    // addPart<Part>(storage, "Gear"); // Теперь это вызовет ошибку на этапе компиляции
    addPart<Assembly>(storage, "Engine Assembly");
    // addPart<Part>(storage, "Screw"); // И это тоже
    addPart<Assembly>(storage, "Chassis Assembly");

    for (const auto &part : storage)
    {
        part->display();
    }
    return 0;
}