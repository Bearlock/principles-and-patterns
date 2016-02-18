#ifndef NUMBEREDOUTPUT_H
#define NUMBEREDOUTPUT_H

#include "BaseDecorator.h"

// Decorator that writes line numbers
// and newlines to passed in ostream
template<typename T>
class NumberedOutput : public BaseDecorator<T> {
public: 
	// Line numbers are 1-based
	int number = 1;
	NumberedOutput(Output<T> *o) : BaseDecorator<T>(o){}
	 ~NumberedOutput(){}

	 // Right justifies output, writes number, colon, line and newline
	 // Increments number in prepartion for next line
	 void write(const T& t){
		BaseDecorator<T>::write("\t " + std::to_string(number) + ": " + t + "\n");
		number++;
	 }
	 void writeString(const std::string&) {};
};

#endif // NUMBEREDOUTPUT_H