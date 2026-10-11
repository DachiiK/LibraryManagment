#include "ResearchPaper.h"

ResearchPaper::ResearchPaper() : LibraryItem(), journal(""), conference("") {}

ResearchPaper::ResearchPaper(int id, std::string title, std::string creator, int publicationYear, bool available, std::string journal, std::string conference)
    : LibraryItem(id, title, creator, publicationYear, available), journal(journal), conference(conference) {}

void ResearchPaper::display(std::ostream& out) const {
    out << "ResearchPaper|" << getId() << "|" << getTitle() << "|" << getCreator() << "|" << getYear() << "|" << isAvailable() << "|" << journal << "|" << conference << "\n";
}

void ResearchPaper::read(std::istream& in) {
    LibraryItem::read(in);
    while (true) {
        std::cout << "Enter Journal: ";
        in >> journal;
        if (!journal.empty()) break;
        std::cout << "Journal cannot be empty!\n";
    }
    while (true) {
        std::cout << "Enter Conference: ";
        in >> conference;
        if (!conference.empty()) break;
        std::cout << "Conference cannot be empty!\n";
    }
}
std::string ResearchPaper::getType() const { return "ResearchPaper"; }
std::string ResearchPaper::getJournal() const { return journal; }
std::string ResearchPaper::getConference() const { return conference; }

void ResearchPaper::saveToFile(std::ofstream& out) const {
    out << "ResearchPaper|" << getId() << "|" << getTitle() << "|" << getCreator() << "|" << getYear() << "|" << isAvailable() << "|" << journal << "|" << conference << "\n";
}

double ResearchPaper::calculateLateFee(double overdueDays) const {
    return overdueDays * 0.2;
}