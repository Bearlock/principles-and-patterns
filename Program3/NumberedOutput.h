#ifndef NUMBEREDOUTPUT_H
#define NUMBEREDOUTPUT_H

#include "BaseDecorator.h"

template<typename T>
class NumberedOutput : public BaseDecorator<T> {
public: 
	int number = 1;
	NumberedOutput(Output<T> *o) : BaseDecorator<T>(o){}
	 ~NumberedOutput(){}
	 void write(const T& t){
		BaseDecorator<T>::write("\t " + std::to_string(number) + ": " + t + "\n");
		number++;
	 }
	 void writeString(const std::string&) {};
};

#endif // NUMBEREDOUTPUT_H