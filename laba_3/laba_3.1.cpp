#include <iostream>
#include <vector>
#include <memory>

class Component {
protected:
    Component() = default;  

public:
    virtual ~Component() = default;  
    virtual void info() const = 0;   
};

class Part : public Component {
private:
    std::string name;

public:
    Part(const std::string& n) : name(n) {}
    
    void info() const override {
        std::cout << "Part: " << name << std::endl;
    }
};

class Assembly : public Component {
private:
    std::string name;
    std::vector<std::shared_ptr<Component>> components;

public:
    Assembly(const std::string& n) : name(n) {}

    void addComponent(std::shared_ptr<Component> component) {
        components.push_back(component);
    }

    void info() const override {
        std::cout << "Assembly: " << name << std::endl;
        for (const auto& component : components) {
            component->info();
        }
    }
};

template<typename T>
void storeComponent(std::vector<std::shared_ptr<Component>>& storage, std::shared_ptr<T> component) {
    storage.push_back(component);
}

int main() {
    std::vector<std::shared_ptr<Component>> storage;

    auto part1 = std::make_shared<Part>("Screw");
    auto part2 = std::make_shared<Part>("Bolt");
    auto assembly1 = std::make_shared<Assembly>("Engine Assembly");
    assembly1->addComponent(part1);
    assembly1->addComponent(part2);

    storeComponent(storage, part1);
    storeComponent(storage, part2);
    storeComponent(storage, assembly1);

    for (const auto& component : storage) {
        component->info();
    }

    return 0;
}
