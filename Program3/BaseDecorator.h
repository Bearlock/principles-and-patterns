#ifndef BASEDECORATOR_H
#define BASEDECORATOR_H

#include "Output.h"

template<typename T>
class BaseDecorator : public Output<T> {
	Output<T> *output;
public:
	BaseDecorator(Output<T> *os)
	{
		output = os;
	}
	void write(const T& t) {
		output->write(t);
	}
	virtual void writeString(const std::string&) = 0;
};

#endif // BASEDECORATOR_H