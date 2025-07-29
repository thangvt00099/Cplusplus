#include <iostream>
#include <sstream>
#include <memory>
#include <list>
#include <vector>
#include <iterator>
#include <map>
#include <stack>
#include <queue>
#include <fstream>
#include <iomanip>
#include <chrono>

enum class BookStatus {
    Available,
    Borrowed,
    Reserved,
    NonAvailable
};

std::string statusToString(BookStatus status) {
    switch (status) {
        case BookStatus::Available:
            return "Available";
        case BookStatus::Borrowed:
            return "Borrowed";
        case BookStatus::Reserved:
            return "Reserved";
        case BookStatus::NonAvailable:
            return "Non available";
        default:
            return "Unknown";
    }
}

struct Date {
    int day;
    int month;
    int year;

    bool isValid() const {
        return (day > 0  && day <= 31) && (month > 0 && month <= 12) && year > 1900;
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << day << "/" << month << "/" << year;
        return oss.str();
    }

    static Date fromInput() {
        Date d;
        std::cout << "Enter date (dd mm yyyy): ";
        std::cin >> d.day >> d.month >> d.year;
        if (!d.isValid()) {
            throw std::runtime_error("Invalid date!");
        }
        return d;
    }
};

//================Book==================
class LibrarySystem;
class User;
class Book {
    public:
        Book(std::string ID, std::string title, 
            std::string author, BookStatus status) : ID(ID), title(title), author(author), status(status) {}
        std::string getID() const;
        std::string getTitle() const;
        BookStatus getStatus() const;
        void changeStatus(BookStatus status);
        std::string printInfo() const;
    
    private:
        std::string ID;
        std::string title;
        std::string author;
        BookStatus status;
    friend class User;
};

std::string Book::getID() const {
    return ID;
}

std::string Book::getTitle() const {
    return title;
}

BookStatus Book::getStatus() const {
    return status;
}

void Book::changeStatus(BookStatus status) {
    this->status = status;
}

std::string Book::printInfo() const {
    std::ostringstream oss;
    oss << "ID: " << ID << " | " << "Title: " << title << " | " << "Author: " << author << " | " << "Status: " << statusToString(status) << std::endl;
    return oss.str();
}

//================User==================
class User {
    public:
        User(std::string ID, std::string name) : ID(ID), name(name) {}
        void borrowedBook(Book book);
        void returnBook(std::string bookID);
        void printHistory() const;
        std::string printInfo() const;

    private:
        std::string ID;
        std::string name;
        std::list<Book> borrowedBooks;
};

void User::borrowedBook(Book book) {
    if (book.status == BookStatus::Available) {
        book.status = BookStatus::Borrowed;
        borrowedBooks.push_front(book);
        std::cout << name << " borrowed: " << book.title << std::endl;
    } else {
        std::cout << "Book is not available!\n";
    }
}

void User::returnBook(std::string bookID) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if ((*it).ID == bookID) {
            (*it).status = BookStatus::Available;
            std::cout << name << " returned: " << (*it).title << std::endl;
            borrowedBooks.erase(it);
            return;
        }
    }
    std::cout << "Book was not borrowed, cannot return!\n";
}

void User::printHistory() const {
    std::cout << "User: " << name << "\nBorrowed books list:\n";
    for (const auto& book : borrowedBooks) {
        std::cout << book.printInfo();
    }
}

std::string User::printInfo() const {
    std::ostringstream oss;
    oss << "ID: " << ID << " | " << "Name: " << name << std::endl;
    return oss.str();
}

//================LibrarySystem==================
class LibrarySystem {
    public:
        void addBook(Book book);
        bool isDuplicate(Book newbBook) const; 

        void addUser(std::string userID, std::string name);
        void borrowBook(std::string userID, std::string bookID);
        void returnBook(std::string userID, std::string bookID);
        void reserveBook(std::string userID, std::string bookID);

        void printUserHistory(std::string userID) const;
        void showActionHistory() const;
        void showAllBooks() const;
        void showAllUsers() const;
        void saveBooksToFile(const std::string& filename);
        void loadBooksFromFile(const std::string& filename);
        void logAction(const std::string& action);
    private:
        std::vector<Book> allBooks;
        std::map<std::string, std::shared_ptr<User>> users;
        std::map<std::string, std::queue<std::string>> reservations;
        std::stack<std::string> actionHistory;
};

void LibrarySystem::addBook(Book book) {
    if (isDuplicate(book)) {
        std::cout << "Book \"" << book.getTitle() << "\" already exists in the library.\n";
        return;
    }
    allBooks.push_back(book);
    std::cout << "Book \"" << book.getTitle() << "\" has been added to the library.\n";
}

bool LibrarySystem::isDuplicate(Book newbBook) const{
    for (const auto& book : allBooks) {
        if (book.getTitle() == newbBook.getTitle()) {
            return true;
        }
    }
    return false;
}

void LibrarySystem::addUser(std::string userID, std::string name) {
    if (users.count(userID) > 0) {
        std::cout << "User with ID " << userID << "already exists.\n";
        return;
    }
    users[userID] = std::make_shared<User>(userID, name);
    actionHistory.push("Added user: " + userID);
}

void LibrarySystem::borrowBook(std::string userID, std::string bookID) {
    auto user = users[userID];
    for (auto& book : allBooks) {
        if (book.getID() == bookID) {
            if (book.getStatus() == BookStatus::Available) {
                user->borrowedBook(book);
                book.changeStatus(BookStatus::Borrowed);
                actionHistory.push("User " + userID + " borrowed book: " + bookID);
            } else {
                std::cout << "Book not available. Added to reservation queue.\n";
                reservations[book.getID()].push(userID);
                actionHistory.push(userID + " reserved " + book.getID());
            }
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void LibrarySystem::returnBook(std::string userID, std::string bookID) {
    auto user = users[userID];
    user->returnBook(bookID);
    for (auto& book : allBooks) {
        if (book.getID() == bookID) {
            book.changeStatus(BookStatus::Available);
            actionHistory.push("User " + userID + " returned book: " + bookID);
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void LibrarySystem::reserveBook(std::string userID, std::string bookID) {
    auto user = users[userID];
    for (auto& book : allBooks) {
        if (book.getID() == bookID) {
            if (book.getStatus() == BookStatus::Available) {
                user->borrowedBook(book);
                book.changeStatus(BookStatus::Borrowed);
                actionHistory.push("User " + userID + " reserved book: " + bookID);
            } else if (book.getStatus() == BookStatus::Borrowed){
                reservations[bookID].push(userID);
                std::cout << "Book is currently borrowed. Added to reservation queue.\n";
                actionHistory.push(userID + " reserved " + bookID);
            } else {
                std::cout << "Book is not available for reservation.\n";
            }
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void LibrarySystem::printUserHistory(std::string userID) const {
    if (users.count(userID) == 0) {
        std::cout << "User not found.\n";
        return;
    }
    users.at(userID)->printHistory();
}

void LibrarySystem::showActionHistory() const {
    std::cout << "Action History:\n";
    std::stack<std::string> temp = actionHistory;
    while (!temp.empty()) {
        std::cout << temp.top() << "\n";
        temp.pop();
    }
}

void LibrarySystem::saveBooksToFile(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw std::runtime_error("Can't open file to save book: " + filename);
    }

    for (const auto& book : allBooks) {
        outFile << book.getID() << ", " << book.getTitle() << ", "
                << statusToString(book.getStatus()) << ", " << book.printInfo() << "\n";
        outFile.close();
    }
}

void LibrarySystem::loadBooksFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw std::runtime_error("File not exist or not open: " + filename);
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string id, title, statusStr;
        std::getline(ss, id, ',');
        std::getline(ss, title, ',');
        std::getline(ss, statusStr, ',');

        BookStatus status = static_cast<BookStatus>(std::stoi(statusStr));
        Book book(id, title, "Unknown", status);
        addBook(book);
    }
    inFile.close();
}

void LibrarySystem::logAction(const std::string& action) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (!logFile.is_open()) return;

    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    logFile << "[" << std::put_time(std::localtime(&time), "%d/%m/%y %H:%M") << "] " << action << "\n";
    logFile.close();
}

void LibrarySystem::showAllBooks() const {
    for (const auto& book : allBooks) {
        std::cout << book.printInfo() << "\n";
    }
}

void LibrarySystem::showAllUsers() const {
    for (const auto& user : users) {
        std::cout << "{" << user.first << ": " << user.second << "}" << " | ";
    }
}

int main() {
    LibrarySystem library;

    // Adding books
    library.addBook(Book("B001", "C++ Programming", "Author A", BookStatus::Available));
    library.addBook(Book("B002", "Data Structures", "Author B", BookStatus::Available));
    library.addBook(Book("B003", "Algorithms", "Author C", BookStatus::Available));

    // Adding users
    library.addUser("U001", "Alice");
    library.addUser("U002", "Bob");

    // Borrowing books
    library.borrowBook("U001", "B001");
    library.borrowBook("U002", "B002");

    // Returning books
    library.returnBook("U001", "B001");

    // Reserving books
    library.reserveBook("U002", "B003");

    // Print user history
    library.printUserHistory("U001");
    library.printUserHistory("U002");

    // Show action history
    library.showActionHistory();

    return 0;
}