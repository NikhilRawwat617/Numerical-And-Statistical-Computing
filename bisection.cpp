#include <iostream>
#include <cmath>
using namespace std;


float f(float a, float b, float c, float d, float x) {
    return (a * x * x * x) + (b * x * x) + (c * x) + d;
}

// Bisection method for finding a root
void bisection(float a, float b, float c, float d, float range1, float range2) {
    float x, value;
    float tolerance = 0.001;
    int maxIterations = 100, iteration = 0;

   
    if (f(a, b, c, d, range1) * f(a, b, c, d, range2) >= 0) {
        cout << "No root found in the given range or multiple roots exist." << endl;
        return;
    }

    cout << fixed;
    cout.precision(4); 

    
    cout << "\nIter\tRange1\tRange2\tMidpoint\tf(x)\n";
    cout << "-------------------------------------------------------------\n";

    do {
        x = (range1 + range2) / 2;
        value = f(a, b, c, d, x);

        cout << iteration + 1 << "\t" << range1 << "\t" << range2 << "\t" << x << "\t\t" << value << endl;

        if (fabs(value) <= tolerance || fabs(range2 - range1) <= tolerance) {
            break;
        }

        if (value * f(a, b, c, d, range1) < 0)
            range2 = x;
        else
            range1 = x;

        iteration++;
    } while (iteration < maxIterations);

    cout << "\nApproximate root (to 3 decimal places) = " << x << endl;
    cout << "f(x) = " << value << endl;
}

int main() {
    float a, b, c, d, range1, range2;

    cout << "Enter the coefficient of x^3: ";
    cin >> a;
    cout << "Enter the coefficient of x^2: ";
    cin >> b;
    cout << "Enter the coefficient of x: ";
    cin >> c;
    cout << "Enter the constant term: ";
    cin >> d;
    cout << "Enter the starting range (range1): ";
    cin >> range1;
    cout << "Enter the ending range (range2): ";
    cin >> range2;

    bisection(a, b, c, d, range1, range2);

    return 0;
}
