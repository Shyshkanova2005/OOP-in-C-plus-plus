#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Author {
    string name;
};

struct Books {
    string title;
    Author author;
    string category;
};

struct Borrowings {
    int BorrowedDate;
    int ReturnedDate;
};


class Library {
private:
    vector<Author> authors;
    vector<Books> books;
    vector<string> categories;
    vector<int> borrowedDates;
    vector<int> returnedDates;

public:
    Library() {}

    void addBook(const Books& book, int borrowedDate, int returnedDate) {
        books.push_back(book);
        borrowedDates.push_back(borrowedDate);
        returnedDates.push_back(returnedDate);
        cout << "Книга " << book.title << endl;
        cout << "Дата взяття книги: " << borrowedDate << "\n";
        cout << "Дата повернення книги: " << returnedDate << "\n";
    }


    void addAuthor(const string& name) {
        Author newAuthor = { name };
        authors.push_back(newAuthor);
        cout << "Автор " << name << endl;
    }

    void addCategory(const string& category) {
        categories.push_back(category);
        cout << "Жанр " << category << endl;
    }

    void displayAllAuthors() {
        cout << "Список всіх авторів:" << endl;
        for (const auto& author : authors) {
            cout << author.name << endl;
        }
    }

    void displayAllCategories() {
        cout << "Список всіх жанрів:" << endl;
        for (const auto& category : categories) {
            cout << category << endl;
        }
    }

    void displayAllBooks() {
        cout << "Список всіх книг:" << endl;
        for (const auto& book : books) {
            cout << "Назва: " << book.title << ", Автор: " << book.author.name << ", Жанр: " << book.category << endl;
        }
    }

    void displayBooksInCategory(const string& categoryName) {
        cout << "Список книг в жанрі \"" << categoryName << endl;
        for (const auto& book : books) {
            if (book.category == categoryName) {
                cout << "Назва: " << book.title << ", Автор: " << book.author.name << endl;
            }
        }
    }

    void displayReturnedBooks() {
        cout << "Список книг, которые были возвращены:" << endl;
        for (size_t i = 0; i < books.size(); ++i) {
            if (returnedDates[i] != 0) {
                cout << "Название: " << books[i].title << ", Автор: " << books[i].author.name << endl;
            }
        }
    }
};

int main() {

    setlocale(LC_CTYPE, "ukr");
    Library myLibrary;


    myLibrary.addAuthor("Джулия Куин");
    myLibrary.addAuthor("Пол Тобін");
    myLibrary.addAuthor("Чарльз Діккенс");


    myLibrary.addCategory("Роман");
    myLibrary.addCategory("Фантастика");
    myLibrary.addCategory("Класика");


    Books book1 = { "Бріджертони", {"Джулия Куин"}, "Роман" };
    Books book2 = { "Відьмак", {"Пол Тобін"}, "Фантастика" };
    Books book3 = { "Великі сподівання", {"Чарльз Діккенс"}, "Класика" };

    myLibrary.addBook(book1, 20240117, 20240220);
    myLibrary.addBook(book2, 20240118, 20240221);
    myLibrary.addBook(book3, 20240119, 20240222);


    myLibrary.displayAllAuthors();
    myLibrary.displayAllCategories();
    myLibrary.displayAllBooks();


    myLibrary.displayBooksInCategory("Класика");
    myLibrary.displayReturnedBooks();
    return 0;
}
