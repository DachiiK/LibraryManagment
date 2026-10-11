#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"

class Magazine : public LibraryItem {
private:
    int issue_number;
    std::string month;

public:
    Magazine();
    Magazine(int id, std::string title, std::string creator, int publicationYear, bool available, int issue_number, std::string month);

    void display(std::ostream& out) const override;
    void read(std::istream& in) override;
    std::string getType() const override;
    
    int getIssue_number() const;
    std::string getMonth() const;

    void saveToFile(std::ofstream& out) const override;
    double calculateLateFee(double overdueDays) const override;
};

#endif