#include "Point.h"

Point::Point(unsigned char luminance=0u): luminance(luminance) {}

unsigned char Point::set(unsigned char luminance){
    this->luminance = luminance;

    return luminance;
}
unsigned char Point::get(){
    return this->luminance;
}
// Point::~Point(){}
