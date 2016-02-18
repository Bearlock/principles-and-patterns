#ifndef STREAMOUTPUT_H
#define STREAMOUTPUT_H

#include "Output.h"

// Concrete class that inherits from 
// Base Output class; writes passed 
// in ostreams to output file
template<typename T>
class StreamOutput : public Output<T> {
    std::ostream& sink;
public:
    explicit StreamOutput(std::ostream& stream) : sink(stream) {}
    void write(const T& t) {
        sink << t;
    }
    void writeString(const std::string& s) {
       sink << s;
    }
};

#endif // STREAMOUTPUT_H


