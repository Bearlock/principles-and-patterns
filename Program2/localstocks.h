#ifndef LOCALSTOCKS_H
#define LOCALSTOCKS_H

#include <iostream>
#include <vector>
#include <fstream>
#include "MyObserver.h"
#include <string>
#include "averageobserver.h"
#include "PercentChangeObserver.h"
#include "CompanyObserver.h"

class LocalStocks {
protected:

std::vector<MyObserver *> observers;
std::vector<std::string> strings;

public:

	//LocalStocks(ifstream file);
	LocalStocks();
	void registerObserver(MyObserver *);
	void notifyObserver();

};

#endif // LOCALSTOCKS_H