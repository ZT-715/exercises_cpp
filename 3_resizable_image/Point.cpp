#include "Point.h"
#include <random>

Point::Point(unsigned char luminance): luminance(luminance) {}

unsigned char Point::set_rand(){
    this->luminance = std::rand()%256;
    return luminance;
}

unsigned char Point::set(unsigned char luminance){
    this->luminance = luminance;
    return luminance;
}
unsigned char Point::get() const{
    return this->luminance;
}
