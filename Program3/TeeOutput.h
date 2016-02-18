#include "BaseDecorator.h"


// Decorator that takes an additional
// ostream as a decorator; allows the
// ability to write to addtional file
// via passed in ostream parameter 
template<typename T>
class TeeOutput : public BaseDecorator<T> {
	std::ostream& teeOust;
public: 
	TeeOutput(Output<T> *out, std::ostream& oust) : teeOust(oust), BaseDecorator<T>(out){}
	 ~TeeOutput(){}
	 void write(const T& t){
		BaseDecorator<T>::write(t);
		teeOust << t;
	 }
	 void writeString(const std::string&) {};
};