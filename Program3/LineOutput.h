#ifndef LINEOUTPUT_H
#define LINEOUTPUT_H

#include "BaseDecorator.h"

template<typename T>
class LineOutput : public BaseDecorator<T> {
public: 
	LineOutput(Output<T> *o) : BaseDecorator<T>(o){}
	 ~LineOutput(){}
	 void write(const T& t){
		BaseDecorator<T>::write(t + "\n");
	 }
	 void writeString(const std::string&) {};
};

#endif // LINEOUTPUT_H