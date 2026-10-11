#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include <string>
#include <iostream>
#include <fstream>

class LibraryItem {
private:
    int id;
    std::string title;
    std::string creator;
    int publicationYear;
    bool available;
    std::string borrowerName;
    std::string borrowDate;

public:
    LibraryItem(int id = 0, std::string title = "", std::string creator = "", int publicationYear = 0, bool available = true);
    virtual ~LibraryItem();

    // Getters and Setters
    int getId() const;
    std::string getTitle() const;
    std::string getCreator() const;
    int getYear() const;
    bool isAvailable() const;
    void setAvailable(bool available);
    std::string getBorrowerName() const;
    std::string getBorrowDate() const;
    void setBorrowerName(const std::string& name);
    void setBorrowDate(const std::string& date);
    
    // Operators
    LibraryItem& operator++();
    void operator++(int);
    LibraryItem& operator--();
    void operator--(int);
    bool operator<(const LibraryItem& other) const;
    bool operator==(const LibraryItem& other) const;
    
    // Pure Virtual Functions
    virtual void display(std::ostream& out) const = 0;
    virtual void read(std::istream& in);
    virtual std::string getType() const = 0;
    virtual void saveToFile(std::ofstream& out) const = 0;
    virtual double calculateLateFee(double overdueDays) const = 0;
};

// Global stream operators declarations
std::ostream& operator<<(std::ostream& out, const LibraryItem& item);
std::istream& operator>>(std::istream& in, LibraryItem& item);

#endif