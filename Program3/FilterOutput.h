#ifndef FILTEROUTPUT_H
#define FILTEROUTPUT_H

#include "BaseDecorator.h"

// Decorator that 'filters', i.e writes only,
// that which fulfills a certain condition
// Two conditions are provide; ContainsHash
// and ContainsTenwordsOrLess
// Takes an additional parameter in the form
// of a numeric string
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
    
    // Unary predicate; checks for "#"
    bool ContainsHash(T t)
    {
    	// Essentially, 'if query doesn't = NULL, return true'
        if (t.find("#") != std::string::npos) { 
        	return true;
        }

        else { 
        	return false; 
        }
    }
    
    // Unary predicate: checks for word length
    bool ContainsTenWordsOrLess(T t)
    {
    	std::string str;
    	int count = 0;

    	// Casts input to a istringstream and reads 
    	// from it. Super handy in this instance.
    	// istringstreams read from a string and
    	// separate by white space. As long as
    	// White space is found, increments count
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


