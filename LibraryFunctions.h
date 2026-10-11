#ifndef LIBRARY_FUNCTIONS_H
#define LIBRARY_FUNCTIONS_H

#include <map>
#include <vector>
#include <memory>
#include "LibraryItem.h"

void safeInputInt(int &x);
void loadItemsFromFile(std::map<int, std::unique_ptr<LibraryItem>>& items, const std::string& file_name);
void addLibraryItem(std::map<int, std::unique_ptr<LibraryItem>>& items);
LibraryItem* SearchByID(std::map<int, std::unique_ptr<LibraryItem>>& items, int ID);
bool searchId(std::map<int, std::unique_ptr<LibraryItem>>& items, int Id);
LibraryItem* SearchByTitle(std::map<int, std::unique_ptr<LibraryItem>>& items);
LibraryItem* SearchByCreator(std::map<int, std::unique_ptr<LibraryItem>>& items);
LibraryItem* SearchByYear(std::map<int, std::unique_ptr<LibraryItem>>& items);

std::vector<LibraryItem*> SortByYear(std::map<int, std::unique_ptr<LibraryItem>>& items);
std::vector<LibraryItem*> SortByAvailability(std::map<int, std::unique_ptr<LibraryItem>>& items);
std::vector<LibraryItem*> SortByType(std::map<int, std::unique_ptr<LibraryItem>>& items);
std::vector<LibraryItem*> SortByTitle(std::map<int, std::unique_ptr<LibraryItem>>& items);

void saveItemsToFile(std::map<int, std::unique_ptr<LibraryItem>>& items);
void borrowAnItem(std::map<int, std::unique_ptr<LibraryItem>>& items);
void returnAnItem(std::map<int, std::unique_ptr<LibraryItem>>& items);
void delateAnItem(std::map<int, std::unique_ptr<LibraryItem>>& items);
void generateReport(const std::map<int, std::unique_ptr<LibraryItem>>& items, const std::string& file_name);
void displayItems(std::map<int, std::unique_ptr<LibraryItem>>& items);
void displayMenu();

#endif