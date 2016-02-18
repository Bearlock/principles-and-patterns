#ifndef COMPANYOBSERVER_H
#define COMPANYOBSERVER_H

#include "MyObserver.h"
#include <unordered_set>

class CompanyObserver : public MyObserver {
private:


public:
	void update(std::vector<std::string> strings) {

		std::ofstream myFile("Company.dat");

		// Set of companies being observed
		std::unordered_set<std::string> companies {"ALL", "BA", "BC", "GBEL", "KFT", "MCD", "TR", "WAG"};

		// For-loop that takes each string in the string vector
		// Breaks it into individual words using an istringstream
		// And finally pushes those words into words vector
		// Doesn't do so if string begins with "Last", i.e date line
		if(myFile.is_open()) {
			for(int i = 0; i < strings.size(); i++) {
				std::string thisStr = strings[i];
				std::string str;
				std::vector<std::string> words;
				std::istringstream is(thisStr);
				while(is >> str) {
					if(str == "Last") {
						myFile << "\n" << thisStr << std::endl;
						break;
					}
					words.push_back(str);
				}

				// Checks for blank lines; if not blank and current ticker
				// Symbol is equal to ticker symbol in companies set, 
				// Write the current string being processed
				if(words.size() != 0) {
					if(companies.find(words.at(words.size() - 8)) != companies.end()) {
						myFile << thisStr << std::endl;
					}
				}
			}
			myFile.close();
		}
	}

};

#endif // COMPANYOBSERVER_H