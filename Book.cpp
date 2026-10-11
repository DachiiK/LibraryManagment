#include "Book.h"

Book::Book() : LibraryItem(), pages(0), genre("") {}

Book::Book(int id, std::string title, std::string creator, int publicationYear, bool available, int pages, std::string genre)
    : LibraryItem(id, title, creator, publicationYear, available), pages(pages), genre(genre) {}

void Book::display(std::ostream& out) const {
    out << "Book|" << getId() << "|" << getTitle() << "|" << getCreator() << "|" << getYear() << "|" << isAvailable() << "|" << pages << "|" << genre << "\n";
}

void Book::read(std::istream& in) {
    LibraryItem::read(in);
    while (true) {
        std::cout << "Enter pages: ";
        if (in >> pages && pages > 0) {
            break;
        } else {
            std::cout << "Invalid! Pages must be a positive number: ";
            in.clear();
            in.ignore(1000, '\n');
        }
    }
    while (true) {
        std::cout << "Enter genre: ";
        in >> genre;
        if (!genre.empty()) break;
        std::cout << "Genre cannot be empty!\n";
    }
}

std::string Book::getType() const { return "Book"; }
int Book::getPages() const { return pages; }
std::string Book::getGenre() const { return genre; }

void Book::saveToFile(std::ofstream& out) const {
    out << getType() << "|" << getId() << "|" << getTitle() << "|" << getCreator() << "|" << getYear() << "|" << isAvailable() << "|" << pages << "|" << genre << "\n";
}

double Book::calculateLateFee(double overdueDays) const {
    return overdueDays * 0.5;
}