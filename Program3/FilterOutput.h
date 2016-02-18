#ifndef FILTEROUTPUT_H
#define FILTEROUTPUT_H

#include "BaseDecorator.h"

template<typename T>
class FilterOutput : public BaseDecorator<T> {
	std::string arg = "";
public:
	FilterOutput(Output<T> *o, std::string s) : arg(s), BaseDecorator<T>(o) {}
	~FilterOutput() {}
	void write(const T& t) {
		if (arg == "1") {
			if (ContainsHash(t)) {
				BaseDecorator<T>::write(t);
			}
		} else if (arg == "2") {
			if (ContainsTenWordsOrLess(t)) {
				BaseDecorator<T>::write(t);
			}
		}
	}
    
	void writeString(const std::string&) {};
    
    bool ContainsHash(T t)
    {
        if (t.find("#") != std::string::npos) { 
        	return true;
        }

        else { 
        	return false; 
        }
    }
    
    bool ContainsTenWordsOrLess(T t)
    {
    	std::string str;
    	int count = 0;
        std::istringstream strBreaker(t);
        while(strBreaker >> str) {
        	count++;
        }
        if (count <= 9) {
        	return true;
        }

        else {
        	return false;
        }
    }
};

#endif //FILTEROUTPUT_H


