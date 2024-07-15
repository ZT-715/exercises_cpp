#include"Image.h"

Image::Image(unsigned  width, unsigned height): width(width), height(height) {
    image = new Point*[height];
    for (unsigned n = 0; n < height; n++){
        image[n] = new Point[width];
    }
}

unsigned char Image::get_point(unsigned row, unsigned column){
    return image[row][column].get();
}
unsigned char Image::set_point(unsigned row, unsigned column, unsigned char luminance) {
    return image[row][column].set(luminance);
}

unsigned Image::get_height(void) const {return this->height;}
unsigned Image::get_width(void) const {return this->width;}

void Image::delete_image() {
    for(unsigned n = 0; n < height; n++){
        delete[] image[n];
    }
}

void Image::set_random(){
    std::srand(std::time(nullptr));

    for(unsigned n = 0; n < height; n++){
        for(unsigned m = 0; m < width; m++){
                image[n][m].set_rand();
        }
    }
}


unsigned Image::set_height(unsigned new_height){
    Point** new_image = new Point*[new_height];
    for(unsigned n = 0; n < new_height; n++){
        new_image[n] = new Point[width];
    }
    
    for(unsigned n = 0; n < new_height; n++){
        for(unsigned m = 0; m < width; m++){
            if(n < this->height){
                new_image[n][m] = Point(image[n][m]);
            }
        }
    }

    delete_image();
    image = new_image;
    return this->height = new_height;
}

unsigned Image::set_width(unsigned new_width){
    Point** new_image = new Point*[height];
    for(unsigned n = 0; n < height; n++){
        new_image[n] = new Point[new_width];
    }
    
    for(unsigned n = 0; n < height; n++){
        for(unsigned m = 0; m < new_width; m++){
            if(m < this->width){
                new_image[n][m] = Point(image[n][m]);
            }
//                else {
//                    new_image[n][m] = Point();
//                }
        }
    }

    delete_image();
    image = new_image;
    return this->width = new_width;
}

void Image::lum_invert(){
    for(unsigned n = 0; n < height; n++) {
        for(unsigned m = 0; m < width; m++){
            image[n][m].set(255u - image[n][m].get());
        }
    }
}

std::string Image::get_image() const {
    std::ostringstream oss;

    oss << '\n';


    for (unsigned n = 0; n < height; n++) {
        for (unsigned m = 0; m < width; m++) {
            unsigned char lum = image[n][m].get();

            oss << "\e[38;2;" << (int)lum << ";" << (int)lum << ";" << (int)lum << "m#";
        }
        oss << '\n'; 
    }

    return oss.str();
}
//        blackText="\e[38;2;0;0;0m"
//        whiteText="\e[38;2;255;255;255m"
//

Image::~Image() {
    delete_image();
}
