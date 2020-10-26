// https://www.hackerrank.com/challenges/rectangle-area/problem

#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */

 class Rectangle {
     protected:
        int width;
        int height;

    public:
        void read_input() {
            cin >> width >> height;
        }
        void display() {
            cout << width << " " << height << endl;
        }

 };

// all varaibles should be either public or protected to be inherited from mother class
 class RectangleArea: public Rectangle {
     public:
        void read_input() {
            Rectangle::read_input();
        }

        void display() {
            cout << this->width * this->height << endl;
        }
 };


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}