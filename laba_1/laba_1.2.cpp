#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Базовый класс "Книга"
class Book {
public:
    string author;
    string title;
    string type; // Художественная или техническая
    Book(const string& author, const string& title, const string& type) : author(author), title(title), type(type) {
        if (author.empty() || title.empty()) {
            throw invalid_argument("Название автора и книги не могут быть пустыми!");
        }
    }
    virtual void printInfo() const = 0;
};

// Класс "Художественная книга"
class FictionBook : public Book {
public:
    FictionBook(const string& author, const string& title) : Book(author, title, "Художественная") {}
    void printInfo() const override {
        cout << "Художественная книга: " << title << " (" << author << ")\n";
    }
};

// Класс "Техническая книга"
class NonFictionBook : public Book {
public:
    NonFictionBook(const string& author, const string& title) : Book(author, title, "Техническая") {}
    void printInfo() const override {
        cout << "Техническая книга: " << title << " (" << author << ")\n";
    }
};
void countAndPrintBooks(const vector<Book*>& library) {
    int fictionCount = 0;
    int nonFictionCount = 0;

    for (auto book : library) {
        if (book->type == "Художественная") {
            ++fictionCount;
        } else if (book->type == "Техническая") {
            ++nonFictionCount;
        }
    }

    cout << "Количество художественной литературы: " << fictionCount << endl;
    cout << "Количество технической литературы: " << nonFictionCount << endl;
}

int main() {
    vector<Book*> library;
    try {
        library.push_back(new FictionBook("Лев Толстой", "Война и мир"));
        library.push_back(new NonFictionBook("Стивен Хокинг", "Краткая история времени"));
        library.push_back(new FictionBook("Джордж Оруэлл", "1984"));
        library.push_back(new NonFictionBook("Брайан Грин", "Элегантная Вселенная"));
    } catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
        return 1; 
    }

    
    cout << "Библиотека:\n";
    for (auto book : library) {
        book->printInfo();
    }
    countAndPrintBooks(library);
    for (auto book : library) {
        delete book;
    }
    system("pause");
    return 0;
}
