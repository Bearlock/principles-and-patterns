#include "LocalStocks.h"

// Constructor opens up Ticker.dat for reading
// Gets each line of file, pushes it into strings vector
LocalStocks::LocalStocks() {
	std::fstream stockFile("Ticker.dat");
	std::string data;
	int i = 0;
	if(stockFile.is_open()) {
		while(std::getline(stockFile, data)) {
			strings.push_back(data);
			i++;
		}
	}

}

// pushes observers into observer vector
void LocalStocks::registerObserver(MyObserver* obs) {
	observers.push_back(obs);
}

// Calls the update() function for each observer
// within the observers vector; uses strings 
// vector as parameter
void LocalStocks::notifyObserver() {
	for(int i = 0; i < observers.size(); i++) {
		observers[i]->update(strings);
	}
}