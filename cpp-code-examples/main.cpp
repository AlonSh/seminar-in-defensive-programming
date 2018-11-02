#include <iostream>

using namespace std;

/* Classes example
// Based on http://www.cplusplus.com/doc/tutorial/classes/
// Definition of a rectangle class with 2 members
class Rectangle {
    int width, height;
public:
    // Declaring public setter method for updating the members of the class
    void set_values(int, int);

    // A public method for calculation using the members of the class
    int area() { return width * height; }
};


// Implementation of the formerly declared setter method
void Rectangle::set_values(int x, int y) {
    width = x;
    height = y;
}

int main() {
    Rectangle rect{};                // Initializing a new object of type Rectangle
    rect.set_values(3, 4);           // Calling it's setter method
    cout << "area: " << rect.area(); // Printing the result of execution of an object's method
    return 0;
}*/


/**
 * A function to safely divide a by b
 * @param a - The number to be divided
 * @param b - The number to divide by
 * @param out - The out parameter where the result is saved (using a pointer)
 * @return 1 if succeeded and 0 otherwise
 */
int divide_values(int a, int b, int *out) {
    if (a < b) { // A simple if test control-flow statement
        return 0;
    }
    if (0 == b) {
        return 0;
    }
    *out = a / b; // Saving value to the integer pointed to by `out`
    return 1;
}

int main() {
    int a = 20, b = 4, c; // Definition of multiple variables of type int
    int *p = &c; // Definition of a variable of type pointer, and accessing `c`s address.

    int succeeded = divide_values(a, b, p); // Function call

    if (succeeded) {
        cout << "a / b: " << c;
    }
    return 0;
}