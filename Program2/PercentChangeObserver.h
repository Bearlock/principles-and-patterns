#ifndef PERCENTCHANGEOBSERVER_H
#define PERCENTCHANGEOBSERVER_H

#include "MyObserver.h"

class PercentChangeObserver : public MyObserver {
private:


public:
	void update(std::vector<std::string> strings) {
		std::ofstream myFile("Percent.dat");
		
		// A vector for each data being observed is created
		// Along with a counter to keep track of snapshot
		// And a variable percentage if it ever needs changing
		int percent = 10;
		int count = 0;
		std::vector<std::string> price;
		std::vector<std::string> tickerSymbol;
		std::vector<std::string> percents;

		// For-loop that takes each string in the string vector
		// Breaks it into individual words using an istringstream
		// And finally pushes those words into words vector
		// Doesn't do so if string begins with "Last", i.e date line
		if(myFile.is_open()) {
			for(int i = 0; i < strings.size(); i++) {
				std::string thisStr = strings[i];
				std::string str;
				std::vector<std::string> stuff;
				std::istringstream is(thisStr);
				while(is >> str) {
					if(str == "Last") {
						myFile << "\n" << thisStr << std::endl;
						break;
					}
					stuff.push_back(str);
				}

				// Uses blank line as delimiter for date snapshots
				// If blank line encountered and counter > 0
				// Output all info in data vectors in for-loop
				// Then, clear all data in vectors to prepare for
				// Subsequent snapshots
				if(stuff.size() == 0) {
					if (count > 0) {
						for (int i = 0; i < count; i++) {
							myFile << tickerSymbol.at(i) << " " << price.at(i) << " " << percents.at(i) << std::endl;
						}
						tickerSymbol.clear();
						price.clear();
						percents.clear();
						count = 0;
					}
				}

				// If current line percentage is >= positive 
				// Or negative percentage threshold, push all
				// Pertinent data into its corresponding vector
				// and increment counter
				else{
					if(std::stod(stuff.at(stuff.size() - 5)) >= percent || std::stod(stuff.at(stuff.size() - 5)) * -1 >= percent) {
						price.push_back(stuff.at(stuff.size() - 7));
						tickerSymbol.push_back(stuff.at(stuff.size() - 8));
						percents.push_back(stuff.at(stuff.size() - 5));
						count++;
					}
				}
			}
			myFile.close();
		}
	}

};

#endif // PERCENTCHANGEOBSERVER_H