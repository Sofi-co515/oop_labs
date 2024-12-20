#include <iostream>
#include <string>

using namespace std;

class Sales {
protected:
    float sales[3]; // массив для хранения продаж за 3 месяца

public:
    void getSalesData() {
        cout << "Введите продажи за последние 3 месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putSalesData() {
        cout << "Продажи за последние 3 месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": " << sales[i] << endl;
        }
    }
};

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
        cin.ignore(); 
    }

    void putdata() {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << endl;
    }
};

class Book : public Publication, public Sales {
protected:
    int pages;

public:
    void getdata() {
        Publication::getdata(); // вызываем getdata() из Publication
        Sales::getSalesData(); // вызываем getSalesData() из Sales
        cout << "Введите количество страниц: ";
        cin >> pages;
        cin.ignore(); 
    }
    void putdata() {
        Publication::putdata(); // вызываем putdata() из Publication
        Sales::putSalesData(); // вызываем putSalesData() из Sales
        cout << "Количество страниц: " << pages << endl;
    }
};
class Tape : public Publication, public Sales {
protected:
    int time;
public:
    void getdata() {
        Publication::getdata(); // вызываем getdata() из Publication
        Sales::getSalesData(); // вызываем getSalesData() из Sales
        cout << "Введите время записи (в минутах): ";
        cin >> time;
        cin.ignore(); 
    }
    void putdata() {
        Publication::putdata(); // вызываем putdata() из Publication
        Sales::putSalesData(); // вызываем putSalesData() из Sales
        cout << "Время записи: " << time << " минут" << endl;
    }
};
int main() {
    Book book1;
    cout << "Введите данные о книге:" << endl;
    book1.getdata();

    Tape tape1;
    cout << "\nВведите данные об аудиозаписи:" << endl;
    tape1.getdata();

    cout << "\nДанные о книге:\n";
    book1.putdata();

    cout << "\nДанные об аудиозаписи:\n";
    tape1.putdata();
    return 0;
}
