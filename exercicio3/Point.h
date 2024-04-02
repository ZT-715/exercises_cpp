/* Class Point defines a element of class Image, wich has a single attribute,
 * luminance.
 *
 * 'luminance' is an unsigned integer and defines the intensity of the specifict point composing an image.
 *
 * The attribute can be accesed through 'Point.get()', and set with
 * 'Point.set(unsigned)'.
 *
 * Calls to set and get return also return the final luminance value.
 */

class Point{
    unsigned luminance;
public:
    Point(unsigned);
    unsigned set(unsigned);
    unsigned get();
//    ~Point();
};

