#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

class Book : public LibraryItem {
private:
    int pages;
    std::string genre;

public:
    Book();
    Book(int id, std::string title, std::string creator, int publicationYear, bool available, int pages, std::string genre);

    void display(std::ostream& out) const override;
    void read(std::istream& in) override;
    std::string getType() const override;
    
    int getPages() const;
    std::string getGenre() const;

    void saveToFile(std::ofstream& out) const override;
    double calculateLateFee(double overdueDays) const override;
};

#endif