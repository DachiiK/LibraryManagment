#include "LibraryFunctions.h"
#include "Book.h"
#include "Magazine.h"
#include "DVD.h"
#include "ResearchPaper.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <cctype>
#include <stdexcept>

using namespace std;

void safeInputInt(int &x) {
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Try again: ";
    }
}

void loadItemsFromFile(map<int, unique_ptr<LibraryItem>>& items, const string& file_name) {
    ifstream fin(file_name);
    if (!fin) {
        throw runtime_error("Critical Error: File '" + file_name + "' could not be found!");
    }

    string line;
    while (getline(fin, line)) {
        if (line.empty() || line[0] == '#') continue;

        stringstream ss(line);
        string type;
        getline(ss, type, '|');
        
        if (type == "Book") {
            int id, year, pages;
            string title, creator, genre;
            bool available;
            string token;
            getline(ss, token, '|'); id = stoi(token);
            getline(ss, title, '|');
            getline(ss, creator, '|');
            getline(ss, token, '|'); year = stoi(token);
            getline(ss, token, '|'); available = (token == "1" || token == "true" || token == "yes");
            getline(ss, token, '|'); pages = stoi(token);
            getline(ss, genre);
            items[id] = make_unique<Book>(id, title, creator, year, available, pages, genre);
        }
        else if (type == "Magazine") {
            int id, year, issue_number;
            string title, creator, month;
            bool available;
            string token;
            getline(ss, token, '|'); id = stoi(token);
            getline(ss, title, '|');
            getline(ss, creator, '|');
            getline(ss, token, '|'); year = stoi(token);
            getline(ss, token, '|'); available = (token == "1" || token == "true" || token == "yes");
            getline(ss, token, '|'); issue_number = stoi(token);
            getline(ss, month);
            items[id] = make_unique<Magazine>(id, title, creator, year, available, issue_number, month);
        }
        else if (type == "DVD") {
            int id, year, duration;
            string title, creator, age_rating;
            bool available;
            string token;
            getline(ss, token, '|'); id = stoi(token);
            getline(ss, title, '|');
            getline(ss, creator, '|');
            getline(ss, token, '|'); year = stoi(token);
            getline(ss, token, '|'); available = (token == "1" || token == "true" || token == "yes");
            getline(ss, token, '|'); duration = stoi(token);
            getline(ss, age_rating);
            items[id] = make_unique<DVD>(id, title, creator, year, available, duration, age_rating);
        }
        else if (type == "ResearchPaper") {
            int id, year;
            string title, creator, journal, conference;
            bool available;
            string token;
            getline(ss, token, '|'); id = stoi(token);
            getline(ss, title, '|');
            getline(ss, creator, '|');
            getline(ss, token, '|'); year = stoi(token);
            getline(ss, token, '|'); available = (token == "1" || token == "true" || token == "yes");
            getline(ss, journal, '|');
            getline(ss, conference);
            items[id] = make_unique<ResearchPaper>(id, title, creator, year, available, journal, conference);
        }
    }
}

void addLibraryItem(map<int, unique_ptr<LibraryItem>>& items) {
    int choice;
    cout << "\n1. Book\n2. Magazine\n3. DVD\n4. Research Paper\nChoice: ";
    safeInputInt(choice);

    unique_ptr<LibraryItem> item;
    switch (choice) {
        case 1: item = make_unique<Book>(); break;
        case 2: item = make_unique<Magazine>(); break;
        case 3: item = make_unique<DVD>(); break;
        case 4: item = make_unique<ResearchPaper>(); break;
        default:
            cout << "Invalid choice\n";
            return;
    }

    cin >> *item;
    int id = item->getId();

    if (items.find(id) != items.end()) {
        cout << "Item with ID " << id << " already exists. Record rejected.\n";
    } else {
        items[id] = move(item);
        cout << "Success: New library item successfully added to the registry.\n";
    }
}

LibraryItem* SearchByID(map<int, unique_ptr<LibraryItem>>& items, int ID) {
    auto it = items.find(ID);
    if (it != items.end()) {
        return it->second.get();
    }
    return nullptr;
}

bool searchId(map<int, unique_ptr<LibraryItem>>& items, int Id) {
    auto it = items.find(Id);
    return it != items.end();
}

LibraryItem* SearchByTitle(map<int, unique_ptr<LibraryItem>>& items) {
    string searchTitle;
    cout << "Enter title: ";
    cin >> searchTitle;
    transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), ::tolower);

    for (auto& [id, item] : items) {
        string itemTitle = item->getTitle();
        transform(itemTitle.begin(), itemTitle.end(), itemTitle.begin(), ::tolower);
        if (itemTitle.find(searchTitle) != string::npos) {
            return item.get();
        }
    }
    return nullptr;
}

LibraryItem* SearchByCreator(map<int, unique_ptr<LibraryItem>>& items) {
    string searchCreator;
    cout << "Enter Creator: ";
    cin >> searchCreator;
    transform(searchCreator.begin(), searchCreator.end(), searchCreator.begin(), ::tolower);

    for (auto& [id, item] : items) {
        string itemCreator = item->getCreator();
        transform(itemCreator.begin(), itemCreator.end(), itemCreator.begin(), ::tolower);
        if (itemCreator == searchCreator) {
            return item.get();
        }
    }
    return nullptr;
}

LibraryItem* SearchByYear(map<int, unique_ptr<LibraryItem>>& items) {
    int publicationYear;
    cout << "Enter publication year: ";
    cin >> publicationYear;
    for (auto& [id, item] : items) {
        if (item->getYear() == publicationYear) {
            return item.get();
        }
    }
    return nullptr;
}

vector<LibraryItem*> SortByYear(map<int, unique_ptr<LibraryItem>>& items) {
    vector<LibraryItem*> sortedItems;
    for (auto& [id, item] : items) {
        sortedItems.push_back(item.get());
    }
    sort(sortedItems.begin(), sortedItems.end(), [](LibraryItem* a, LibraryItem* b) {
        return a->getYear() < b->getYear();
    });
    return sortedItems;
}

vector<LibraryItem*> SortByAvailability(map<int, unique_ptr<LibraryItem>>& items) {
    vector<LibraryItem*> sortedItems;
    for (auto& [id, item] : items) {
        sortedItems.push_back(item.get());
    }
    sort(sortedItems.begin(), sortedItems.end(), [](LibraryItem* a, LibraryItem* b) {
        return a->isAvailable() < b->isAvailable();
    });
    return sortedItems;
}

vector<LibraryItem*> SortByType(map<int, unique_ptr<LibraryItem>>& items) {
    vector<LibraryItem*> sortedItems;
    for (auto& [id, item] : items) {
        sortedItems.push_back(item.get());
    }
    sort(sortedItems.begin(), sortedItems.end(), [](LibraryItem* a, LibraryItem* b) {
        return a->getType() < b->getType();
    });
    return sortedItems;
}

vector<LibraryItem*> SortByTitle(map<int, unique_ptr<LibraryItem>>& items) {
    vector<LibraryItem*> sortedItems;
    for (auto& [id, item] : items) {
        sortedItems.push_back(item.get());
    }
    sort(sortedItems.begin(), sortedItems.end(), [](LibraryItem* a, LibraryItem* b) {
        return a->getTitle() < b->getTitle();
    });
    return sortedItems;
}

void saveItemsToFile(map<int, unique_ptr<LibraryItem>>& items) {
    ofstream out("data.txt");
    for (auto& [id, item] : items) {
        item->saveToFile(out); 
    }
    out.close();
}

void borrowAnItem(map<int, unique_ptr<LibraryItem>>& items) {
    int Id;
    cout << "Enter item ID: ";
    cin >> Id;

    auto it = items.find(Id);
    if (it == items.end()) {
        cout << "Item not found!\n";
        return;
    }
    if (!it->second->isAvailable()) {
        cout << "Item already borrowed!\n";
        return;
    }

    string borrowerName, borrowDate;
    cout << "Enter borrower name: ";
    cin >> borrowerName;
    cout << "Enter borrow date (DD/MM/YYYY): ";
    cin >> borrowDate;

    it->second->setAvailable(false);
    it->second->setBorrowerName(borrowerName);
    it->second->setBorrowDate(borrowDate);
    cout << "Item borrowed successfully!\n";
}

void returnAnItem(map<int, unique_ptr<LibraryItem>>& items) {
    int Id;
    double overdueDays;
    cout << "Enter ID of the item: ";
    cin >> Id;

    auto it = items.find(Id);
    if (it == items.end()) {
        cout << "Item not found!\n";
        return;
    }
    if (it->second->isAvailable()) {
        cout << "This item is already in the library!\n";
        return;
    }

    cout << "Borrower: " << it->second->getBorrowerName() << "\n";
    cout << "Borrow Date: " << it->second->getBorrowDate() << "\n";
    cout << "Enter number of overdue days: ";
    cin >> overdueDays;

    double fee = it->second->calculateLateFee(overdueDays);
    it->second->setAvailable(true);
    it->second->setBorrowerName("");
    it->second->setBorrowDate("");

    cout << "Item returned successfully!\n";
    cout << "Late fee: " << fee << " GEL\n";
}

void delateAnItem(map<int, unique_ptr<LibraryItem>>& items) {
    int Id;
    cout << "Enter Id of the product you want to delete: ";
    cin >> Id;
    if (searchId(items, Id)) {
        items.erase(Id);
        cout << "Item deleted successfully\n";
    } else {
        cout << "Couldn't find Item with that Id\n";
    }
}

void generateReport(const map<int, unique_ptr<LibraryItem>>& items, const string& file_name) {
    if (items.empty()) {
        throw runtime_error("Report Failure: Cannot generate a report because the library database is empty.");
    }

    ofstream fout(file_name);
    if (!fout) {
        throw runtime_error("Report Failure: Unable to create or open '" + file_name + "' for exporting the report.");
    }

    int availableItems = 0, borrowedItems = 0;
    int book = 0, magazine = 0, dvd = 0, researchPaper = 0;
    
    LibraryItem* oldest = items.begin()->second.get();
    LibraryItem* newest = items.begin()->second.get();

    for (const auto& it : items) {
        if (*it.second < *oldest) {
            oldest = it.second.get();
        }
        if (*newest < *it.second) {
            newest = it.second.get();
        }
        
        if (it.second->isAvailable()) {
            availableItems++;
        } else {
            borrowedItems++;
        }

        if (it.second->getType() == "Book") { book++; }
        else if (it.second->getType() == "Magazine") { magazine++; }
        else if (it.second->getType() == "DVD") { dvd++; }
        else if (it.second->getType() == "ResearchPaper") { researchPaper++; }
    }

    fout << "          LIBRARY STATUS REPORT            \n";
    fout << "Total number of items: " << items.size() << "\n\n";
    fout << "--- AVAILABILITY STATISTICS ---\n";
    fout << "Total number of available items: " << availableItems << "\n";
    fout << "Total number of borrowed items: " << borrowedItems << "\n\n";
    fout << "Total number of Books: " << book << "\n";
    fout << "Total number of Magazines: " << magazine << "\n";
    fout << "Total number of DVDs: " << dvd << "\n";
    fout << "Total number of Research Papers: " << researchPaper << "\n\n";
    
    fout << "Oldest Item: ";
    oldest->display(fout); 
    fout << "Newest Item: ";
    newest->display(fout); 

    fout.close();
    cout << "Success: Library report successfully exported to '" << file_name << "'\n";
}

void displayItems(map<int, unique_ptr<LibraryItem>>& items) {
    for (auto& it : items) {
        it.second->display(cout);
    }
}

void displayMenu() {
    cout << "\n===== Library Management System =====\n";
    cout << "1. Add a New Library Item\n";
    cout << "2. Display All Library Items\n";
    cout << "3. Search Library Items by ID\n";
    cout << "4. Search Library Items by Title\n";
    cout << "5. Search Library Items by Creator\n";
    cout << "6. Search Library Items by Year\n";
    cout << "7. Borrow an Item\n";
    cout << "8. Return an Item\n";
    cout << "9. Delete an Item\n";
    cout << "10. Sort Library Items by Year\n";
    cout << "11. Sort Library Items by type\n";
    cout << "12. Sort Library Items by Availability\n";
    cout << "13. Sort Library Items By title\n";
    cout << "14. Save Items to a File\n";
    cout << "15. Load Items from a File\n";
    cout << "16. Generate library report\n";
    cout << "17. Save and exit\n\n";
    cout << "Choose an option: ";
}