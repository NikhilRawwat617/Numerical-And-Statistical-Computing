#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


double f(double x, double a, double b, double c, double d) {
    return a * x * x * x + b * x * x + c * x + d;
}

double f_derivative(double x, double a, double b, double c) {
    return 3 * a * x * x + 2 * b * x + c;
}

int main() {
    double a, b, c, d;
    double x0, x1, f0, df0, e;
    int max_iter, step = 1;

    cout << setprecision(6) << fixed;

  
    cout << "Cubic equation: ax^3 + bx^2 + cx + d = 0" << endl;
    cout << "Enter coefficients a, b, c, d: ";
    cin >> a >> b >> c >> d;

 
    cout << "Enter initial guess: ";
    cin >> x0;

    cout << "Enter tolerable error: ";
    cin >> e;

    cout << "Enter maximum iterations: ";
    cin >> max_iter;

    cout << "\nStep\tx0\t\tf(x0)\t\tx1\t\tError\n";

    do {
        f0 = f(x0, a, b, c, d);
        df0 = f_derivative(x0, a, b, c);

        if (df0 == 0.0) {
            cout << "Error: Derivative is zero. Try a different guess.\n";
            return -1;
        }

        x1 = x0 - f0 / df0;

        cout << step << "\t" << x0 << "\t" << f0 << "\t" << x1 << "\t" << fabs(x1 - x0) << endl;

        if (fabs(x1 - x0) < e)
            break;

        x0 = x1;
        step++;

        if (step > max_iter) {
            cout << "Method did not converge within max iterations.\n";
            return -1;
        }

    } while (true);

    cout << "\nApproximate root: " << x1 << endl;

    return 0;
}
