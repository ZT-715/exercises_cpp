#include "Point.h"

Point::Point(unsigned luminance=0u): luminance(luminance) {}

unsigned Point::set(unsigned luminance){
    this->luminance = luminance;

    return luminance;
}
unsigned Point::get(){
    return this->luminance;
}
// Point::~Point(){}
