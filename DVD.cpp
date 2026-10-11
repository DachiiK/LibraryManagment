#include "DVD.h"

DVD::DVD() : LibraryItem(), duration(0), age_rating("") {}

DVD::DVD(int id, std::string title, std::string creator, int publicationYear, bool available, int duration, std::string age_rating)
    : LibraryItem(id, title, creator, publicationYear, available), duration(duration), age_rating(age_rating) {}

void DVD::display(std::ostream& out) const {
    out << "DVD|" << getId() << "|" << getTitle() << "|" << getCreator() << "|" << getYear() << "|" << isAvailable() << "|" << duration << "|" << age_rating << "\n";
}

void DVD::read(std::istream& in) {
    LibraryItem::read(in);
    while (true) {
        std::cout << "Enter duration (minutes): ";
        if (in >> duration && duration > 0) {
            break;
        } else {
            std::cout << "Invalid! Duration must be a positive number: ";
            in.clear();
            in.ignore(1000, '\n');
        }
    }
    while (true) {
        std::cout << "Enter Age Rating: ";
        in >> age_rating;
        if (!age_rating.empty()) break;
        std::cout << "Age rating cannot be empty!\n";
    }
}

std::string DVD::getType() const { return "DVD"; }
int DVD::getDuration() const { return duration; }
std::string DVD::getAge_rating() const { return age_rating; }

void DVD::saveToFile(std::ofstream& out) const {
    out << "DVD|" << getId() << "|" << getTitle() << "|" << getCreator() << "|" << getYear() << "|" << isAvailable() << "|" << duration << "|" << age_rating << "\n";
}

double DVD::calculateLateFee(double overdueDays) const {
    return overdueDays;
}