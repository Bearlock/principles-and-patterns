#ifndef AVERAGEOBSERVER_H
#define AVERAGEOBSERVER_H

#include "MyObserver.h"

class AverageObserver : public MyObserver {
private:

public:
	void update(std::vector<std::string> strings) {

		std::ofstream myFile("Average.dat");

		int count = 0;
		double total = 0;

		// For-loop that takes each string in the string vector
		// Breaks it into individual words using an istringstream
		// And finally pushes those words into words vector
		// Doesn't do so if string begins with "Last", i.e date line
		if (myFile.is_open()) {
			for(int i = 0; i < strings.size(); i++) {
				std::string thisStr = strings[i];
				std::string str;
				std::vector<std::string> words;
				std::istringstream is(thisStr);
				while(is >> str) {
					if(str == "Last") {
						myFile << thisStr << std::endl;
						break;
					}
					words.push_back(str);
				}
				// Uses blank lines as a delimiter between date snapshots
				// If a line is blank, outputs averageprice for that snapshot
				if(words.size() == 0) {
					if (count > 0) {
						myFile << (total / count) << '\n' << std::endl;
						count = 0;
						total = 0;
					}
				}

				// If the line isn't blank, its still in a snapshot
				// It then increments count by 1 and price by current line price
				else{
					total = total + std::stod(words.at(words.size() - 7));
					count++;
				}
			}
			myFile.close();
		}
	}

};

#endif // AVERAGEOBSERVER_H