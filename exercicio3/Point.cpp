#include "Point.h"

Point::Point(unsigned char luminance): luminance(luminance) {}

unsigned char Point::set(unsigned char luminance){
    this->luminance = luminance;

    return luminance;
}
unsigned char Point::get() const{
    return this->luminance;
}
// Point::~Point(){}
