#include"Point.h"
#include<iostream>
#include<sstream>
#include<string>
#include<random>
#include<ctime>

class Image: private Point {
    Point** image;
    unsigned width;
    unsigned height;

public:
    explicit Image(unsigned  width=0u, unsigned height=0u);

    unsigned char get_point(unsigned row, unsigned column);
    unsigned char set_point(unsigned row, unsigned column, unsigned char luminance);
    unsigned get_height(void) const ;
    unsigned get_width(void) const ;
 
    void delete_image();
    void set_random();
 
    unsigned set_height(unsigned new_height);
    unsigned set_width(unsigned new_width);
    void lum_invert();
    std::string get_image() const;

    ~Image();
};


