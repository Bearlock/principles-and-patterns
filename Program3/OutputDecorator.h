#pragma once

#include "Output.h"
#include <string>

template<typename T>
class OutputDecorator : public Output<T> {
	Output<T> *output;
public:
	OutputDecorator(Output<T> *o)
	{
		output = o;
	}
	void write(const T& t) {
		output->write(t);
	}
	virtual void writeString(const std::string&) = 0;
};
