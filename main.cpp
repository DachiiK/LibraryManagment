#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include "LibraryItem.h"
#include "LibraryFunctions.h"

using namespace std;

int main() {
    map<int, unique_ptr<LibraryItem>> items;
    int choice, Id;
    LibraryItem* searchedItem = nullptr; 

    do {
        displayMenu();
        safeInputInt(choice);

        switch (choice) {
            case 1:
                addLibraryItem(items);
                break;
            case 2:
                displayItems(items);
                break;
            case 3:
                cout << "Enter Id you want to search: ";
                cin >> Id;
                searchedItem = SearchByID(items, Id);
                if (searchedItem != nullptr) {
                    searchedItem->display(cout);
                } else {
                    cout << "Couldn't find item\n";
                }
                break;
            case 4:
                searchedItem = SearchByTitle(items);
                if (searchedItem != nullptr) {
                    searchedItem->display(cout);
                } else {
                    cout << "Couldn't find item\n";
                }
                break;
            case 5:
                searchedItem = SearchByCreator(items);
                if (searchedItem != nullptr) {
                    searchedItem->display(cout);
                } else {
                    cout << "Couldn't find item\n";
                }
                break;
            case 6:
                searchedItem = SearchByYear(items);
                if (searchedItem != nullptr) {
                    searchedItem->display(cout);
                } else {
                    cout << "Couldn't find item\n";
                }
                break;
            case 7:
                borrowAnItem(items);
                break;
            case 8:
                returnAnItem(items);
                break;
            case 9:
                delateAnItem(items);
                break;
            case 10: {
                vector<LibraryItem*> sorted = SortByYear(items);
                for (auto it : sorted) it->display(cout);
                break;
            }
            case 11: {
                vector<LibraryItem*> sorted = SortByType(items);
                for (auto it : sorted) it->display(cout);
                break;
            }
            case 12: {
                vector<LibraryItem*> sorted = SortByAvailability(items);
                for (auto it : sorted) it->display(cout);
                break;
            }
            case 13: {
                vector<LibraryItem*> sorted = SortByTitle(items);
                for (auto it : sorted) it->display(cout);
                break;
            }
            case 14:
                saveItemsToFile(items);
                break;
            case 15:
                try {
                    loadItemsFromFile(items, "data.txt");
                } catch (const std::exception& e) {
                    cout << e.what() << "\n";
                }
                break;
            case 16:
                try {
                    generateReport(items, "out.txt");
                } catch (const std::exception& e) {
                    cout << e.what() << "\n";
                }
                break;
            case 17:
                cout << "Program finished\n";
                break;
            default:
                cout << "Invalid option\n";
        }
    } while (choice != 17); 
    return 0;
}