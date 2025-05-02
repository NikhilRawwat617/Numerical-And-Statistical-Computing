#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main() {
    float a[3][4];  
    float x[3] = {0, 0, 0};  
    float x_new[3];
    float e1, e2, e3, e;
    int step = 1;

    cout << setprecision(6) << fixed;

    // Input equations
    cout << "Enter coefficients of 3 equations (a11 a12 a13 b1):\n";
    for (int i = 0; i < 3; i++) {
        cout << "Equation " << i + 1 << ": ";
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }

    
    cout << "Enter tolerable error: ";
    cin >> e;

    cout << endl << "Count\tx\t\ty\t\tz" << endl;

    do {
      
        float x0 = x[0], y0 = x[1], z0 = x[2];

       
        x_new[0] = (a[0][3] - (a[0][1] * y0 + a[0][2] * z0)) / a[0][0];
        x_new[1] = (a[1][3] - (a[1][0] * x0 + a[1][2] * z0)) / a[1][1];
        x_new[2] = (a[2][3] - (a[2][0] * x0 + a[2][1] * y0)) / a[2][2];

        cout << step << "\t" << x_new[0] << "\t" << x_new[1] << "\t" << x_new[2] << endl;

       
        e1 = fabs(x[0] - x_new[0]);
        e2 = fabs(x[1] - x_new[1]);
        e3 = fabs(x[2] - x_new[2]);

    
        for (int i = 0; i < 3; i++) {
            x[i] = x_new[i];
        }

        step++;
    } while (e1 > e || e2 > e || e3 > e);

    cout << endl << "Solution: x = " << x[0] << ", y = " << x[1] << ", z = " << x[2] << endl;

    return 0;
}
