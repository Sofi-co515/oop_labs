#include <iostream>
#include <string>
using namespace std;
class Publication {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Введите название: ";
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
        cin.ignore(); // очищаем буфер ввода после ввода цены
    }
    void putdata() {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << endl;
    }
};
class Book : public Publication {
protected:
    int pages;
public:
    void getdata() {
        Publication::getdata(); // вызываем getdata() из базового класса
        cout << "Введите количество страниц: ";
        cin >> pages;
        cin.ignore(); // очищаем буфер ввода после ввода количества страниц
    }
    void putdata() {
        Publication::putdata(); // вызываем putdata() из базового класса
        cout << "Количество страниц: " << pages << endl;
    }
};
class Tape : public Publication {
protected:
    int time;
public:
    void getdata() {
        Publication::getdata(); 
        cout << "Введите время записи (в минутах): ";
        cin >> time;
        cin.ignore(); 
    }
    void putdata() {
        Publication::putdata();
        cout << "Время записи: " << time << " минут" << endl;
    }
};
int main() {
    Book book1;
    cout << "Введите данные о книге:" << endl;
    book1.getdata();
    Tape tape1;
    cout << "Введите данные об аудиозаписи:" << endl;
    tape1.getdata();
    cout << "\nДанные о книге:\n";
    book1.putdata();
    cout << "\nДанные об аудиозаписи:\n";
    tape1.putdata();
    return 0;
}
