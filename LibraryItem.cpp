#include "LibraryItem.h"

LibraryItem::LibraryItem(int id, std::string title, std::string creator, int publicationYear, bool available)
    : id(id), title(title), creator(creator), publicationYear(publicationYear), available(available) {}

LibraryItem::~LibraryItem() {}

int LibraryItem::getId() const { return id; }
std::string LibraryItem::getTitle() const { return title; }
std::string LibraryItem::getCreator() const { return creator; }
int LibraryItem::getYear() const { return publicationYear; }
bool LibraryItem::isAvailable() const { return available; }
void LibraryItem::setAvailable(bool available) { this->available = available; }
std::string LibraryItem::getBorrowerName() const { return borrowerName; }
std::string LibraryItem::getBorrowDate() const { return borrowDate; }
void LibraryItem::setBorrowerName(const std::string& name) { borrowerName = name; }
void LibraryItem::setBorrowDate(const std::string& date) { borrowDate = date; }

LibraryItem& LibraryItem::operator++() {
    this->publicationYear++;
    return *this;
}
void LibraryItem::operator++(int) {
    this->publicationYear++;
}
LibraryItem& LibraryItem::operator--() {
    this->publicationYear--;
    return *this;
}
void LibraryItem::operator--(int) {
    this->publicationYear--;
}
bool LibraryItem::operator<(const LibraryItem& other) const {
    return this->publicationYear < other.publicationYear;
}
bool LibraryItem::operator==(const LibraryItem& other) const {
    return this->publicationYear == other.publicationYear;
}

void LibraryItem::read(std::istream& in) {
    // ID — must be positive
    while (true) {
        std::cout << "Enter ID: ";
        if (in >> id && id > 0) {
            break;
        } else {
            std::cout << "Invalid input! ID must be a positive number: ";
            in.clear();
            in.ignore(1000, '\n');
        }
    }

    // Title — cannot be empty
    while (true) {
        std::cout << "Enter Title: ";
        in >> title;
        if (!title.empty()) break;
        std::cout << "Title cannot be empty!\n";
    }

    // Creator — cannot be empty
    while (true) {
        std::cout << "Enter Creator: ";
        in >> creator;
        if (!creator.empty()) break;
        std::cout << "Creator cannot be empty!\n";
    }

    // Year — must be between 1450 and current year
    while (true) {
        std::cout << "Enter publication year (1450-2026): ";
        if (in >> publicationYear && publicationYear >= 1450 && publicationYear <= 2026) {
            break;
        } else {
            std::cout << "Invalid! Year must be between 1450 and 2026: ";
            in.clear();
            in.ignore(1000, '\n');
        }
    }

    // Availability
    while (true) {
        std::cout << "Enter Available (1 = available, 0 = borrowed): ";
        if (in >> available && (available == 0 || available == 1)) {
            break;
        } else {
            std::cout << "Invalid input! Please enter 0 or 1.\n";
            in.clear();
            in.ignore(1000, '\n');
        }
    }
}

std::ostream& operator<<(std::ostream& out, const LibraryItem& item) {
    item.display(out);
    return out;
}

std::istream& operator>>(std::istream& in, LibraryItem& item) {
    item.read(in);
    return in;
}