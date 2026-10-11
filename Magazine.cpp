#include "Magazine.h"

Magazine::Magazine() : LibraryItem(), issue_number(0), month("") {}

// Fixed matching base initialization syntax
Magazine::Magazine(int id, std::string title, std::string creator, int publicationYear, bool available, int issue_number, std::string month)
    : LibraryItem(id, title, creator, publicationYear, available), issue_number(issue_number), month(month) {}

void Magazine::display(std::ostream& out) const {
    out << "Magazine|" << getId() << "|" << getTitle() << "|" << getCreator() << "|" << getYear() << "|" << isAvailable() << "|" << issue_number << "|" << month << "\n";
}

void Magazine::read(std::istream& in) {
    LibraryItem::read(in);
    while (true) {
        std::cout << "Enter Issue Number: ";
        if (in >> issue_number && issue_number > 0) {
            break;
        } else {
            std::cout << "Invalid! Issue number must be positive: ";
            in.clear();
            in.ignore(1000, '\n');
        }
    }
    while (true) {
        std::cout << "Enter Month: ";
        in >> month;
        if (!month.empty()) break;
        std::cout << "Month cannot be empty!\n";
    }
}

std::string Magazine::getType() const { return "Magazine"; }
int Magazine::getIssue_number() const { return issue_number; }
std::string Magazine::getMonth() const { return month; }

void Magazine::saveToFile(std::ofstream& out) const {
    out << "Magazine|" << getId() << "|" << getTitle() << "|" << getCreator() << "|" << getYear() << "|" << isAvailable() << "|" << issue_number << "|" << month << "\n";
}

double Magazine::calculateLateFee(double overdueDays) const {
    return overdueDays * 0.3;
}