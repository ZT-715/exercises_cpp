/* Class Point defines a element of class Image, wich has a single attribute,
 * luminance.
 *
 * 'luminance' is an 8 bit unsigned integer and defines the intensity of the specifict point composing an image.
 *
 * The attribute can be accesed through 'Point.get()', and set with
 * 'Point.set(unsigned char)'.
 *
 * Calls to set and get return also return the final luminance value.
 */

class Point{
    unsigned char luminance;
public:
    Point(unsigned char);
    unsigned char set(unsigned char);
    unsigned char get();
//    ~Point();
};

