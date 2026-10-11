#ifndef DVD_H
#define DVD_H

#include "LibraryItem.h"

class DVD : public LibraryItem {
private:
    int duration;
    std::string age_rating;

public:
    DVD();
    DVD(int id, std::string title, std::string creator, int publicationYear, bool available, int duration, std::string age_rating);

    void display(std::ostream& out) const override;
    void read(std::istream& in) override;
    std::string getType() const override;
    
    int getDuration() const;
    std::string getAge_rating() const;

    void saveToFile(std::ofstream& out) const override;
    double calculateLateFee(double overdueDays) const override;
};

#endif