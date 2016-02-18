#include "localstocks.h"

int main() {
	
	// New LocalStocks object is created and
	// One of each type of observer is created
	// Then subsequently registred and notified
	LocalStocks local;
	AverageObserver *avg = new AverageObserver();
	PercentChangeObserver *per = new PercentChangeObserver();
	CompanyObserver *com = new CompanyObserver();

	local.registerObserver(avg);
	local.registerObserver(per);
	local.registerObserver(com);
	local.notifyObserver();

}