#ifndef RESEARCH_PAPER_H
#define RESEARCH_PAPER_H

#include "LibraryItem.h"

class ResearchPaper : public LibraryItem {
private:
    std::string journal;
    std::string conference;

public:
    ResearchPaper();
    ResearchPaper(int id, std::string title, std::string creator, int publicationYear, bool available, std::string journal, std::string conference);

    void display(std::ostream& out) const override;
    void read(std::istream& in) override;
    std::string getType() const override;
    
    std::string getJournal() const;
    std::string getConference() const;

    void saveToFile(std::ofstream& out) const override;
    double calculateLateFee(double overdueDays) const override;
};

#endif