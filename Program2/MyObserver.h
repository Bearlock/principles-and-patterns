#ifndef MYOBSERVER_H
#define MYOBSERVER_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <ostream>
#include <fstream>

class MyObserver {
private:

public:
	virtual void update(std::vector<std::string>) = 0;
	virtual ~MyObserver() {}
};

#endif // MYOBSERVER_H