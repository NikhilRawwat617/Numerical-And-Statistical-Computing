#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double f(double x, double a, double b, double c, double d) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    double a, b, c, d;       
    double x0, x1, x2;       
    double f0, f1, f2, e;     
    int max_iter, step = 1;

    cout << setprecision(6) << fixed;

    
    cout << "Cubic equation: ax^3 + bx^2 + cx + d = 0\n";
    cout << "Enter coefficients a, b, c, d: ";
    cin >> a >> b >> c >> d;

    
    cout << "Enter initial guess x0: ";
    cin >> x0;
    cout << "Enter initial guess x1: ";
    cin >> x1;

    
    f0 = f(x0, a, b, c, d);
    f1 = f(x1, a, b, c, d);

    if (f0 * f1 > 0) {
        cout << "Error: f(x0) and f(x1) must have opposite signs.\n";
        return -1;
    }

    // Input error and iteration limit
    cout << "Enter tolerable error: ";
    cin >> e;
    cout << "Enter maximum iterations: ";
    cin >> max_iter;

    cout << "\nStep\tx0\t\tx1\t\tx2\t\tf(x2)\n";

    do {
        
        x2 = (x0 * f1 - x1 * f0) / (f1 - f0);
        f2 = f(x2, a, b, c, d);

        cout << step << "\t" << x0 << "\t" << x1 << "\t" << x2 << "\t" << f2 << endl;

        if (fabs(f2) < e) break;

        
        if (f0 * f2 < 0) {
            x1 = x2;
            f1 = f2;
        } else {
            x0 = x2;
            f0 = f2;
        }

        step++;
        if (step > max_iter) {
            cout << "Method did not converge within max iterations.\n";
            return -1;
        }

    } while (true);

    cout << "\nApproximate root: " << x2 << endl;

    return 0;
}
