#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

// Validation functions 

// Перевірка для n (натуральне число)
bool isValidN(int n) {
    return n > 0;
}

// Перевірка для r (радіус > 0)
bool isValidR(float r) {
    return r > 0;
}

// Перевірка x для логарифму (1 + cos(x) > 0)
bool isValidXLog(double x) {
    return (1 + cos(x)) > 0;
}

// Task 1 
bool isInsideVar11(float x, float y, float r)
{
    if (x < 0) return false;
    if (x * x + y * y > r * r) return false;
    if (y < -x + r) return false;
    return true;
}

void task1()
{
    int n;
    float r;

    cout << "1: Count points in region\n";

    do {
        cout << "Enter number of points n: ";
        cin >> n;
        if (!isValidN(n)) {
            cout << "Invalid input! Enter positive integer n.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!isValidN(n));

    do {
        cout << "Enter radius r (> 0): ";
        cin >> r;
        if (!isValidR(r)) {
            cout << "Invalid input! Enter positive number r.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!isValidR(r));

    int insideCount = 0;

    for (int i = 1; i <= n; i++) {
        float x, y;

        cout << "\nPoint " << i << ":\n";

        cout << "  Enter x: ";
        while (!(cin >> x)) {
            cout << "  Invalid input! Enter number for x: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "  Enter y: ";
        while (!(cin >> y)) {
            cout << "  Invalid input! Enter number for y: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (isInsideVar11(x, y, r)) {
            cout << "  -> INSIDE region \n";
            insideCount++;
        }
        else {
            cout << "  -> OUTSIDE region \n";
        }
    }

    cout << "\nTotal points inside region = " << insideCount << endl;
}

// Task 2 
void task_2() {
    double x;
    int n;

    cout << "2: Compute series with every 3rd term\n";

    do {
        cout << "Enter x: ";
        cin >> x;
        if (!isValidXLog(x)) {
            cout << "Error: 1 + cos(x) must be > 0\n";
        }
    } while (!isValidXLog(x));

    do {
        cout << "Enter n (natural number): ";
        cin >> n;
        if (!isValidN(n)) {
            cout << "Invalid n! Enter positive integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!isValidN(n));

    double a = 1 + cos(x);
    double sum = 0.0;

    cout << "\nEvery 3rd element of the series:\n";

    for (int k = 1; k <= n; k++) {
        double term = pow(-1, k) / (k * pow(a, k));
        sum += term;

        if (k % 3 == 0) {
            cout << "k = " << k << "   term = " << term << endl;
        }
    }

    double result = log(a) - sum;

    cout << "\nResult = " << result << endl;
}

// Task 3 
void task_series() {
    double x;
    const double epsilon = 1e-7;
    const double g = 1e5;

    cout << "3: Investigate convergence of series\n";
    cout << "Enter x: ";
    while (!(cin >> x)) {
        cout << "Invalid input. Enter x again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (fabs(x) > 1.0) {
        cout << "Since |x| > 1, the series diverges.\n";
        return;
    }

    double sum = 0.0;
    int n = 1;
    double term;

    while (true) {
        term = sqrt((pow(x, n) + 1) / (pow(x, n) + n));

        if (fabs(term) < epsilon) {
            cout << "Term " << n << " < epsilon. Series converges.\n";
            break;
        }

        if (fabs(term) > g) {
            cout << "Term " << n << " > g. Series diverges.\n";
            break;
        }

        sum += term;
        n++;

        if (n > 100000) {
            cout << "Reached max iterations. Series likely diverges.\n";
            break;
        }
    }

    cout << "Partial sum = " << sum << endl;
}

// Menu 
int main() {
    int choice;

    do {
        cout << endl;
        cout << "----------------------------------" ;
        cout << "\n              MENU \n";
        cout << "----------------------------------" << endl;
        cout << "1. Count points in region\n";
        cout << "2. Compute series with every 3rd term\n";
        cout << "3. Investigate convergence of series\n";
        cout << "0. Exit\n";
        cout << "Choose task: ";

        while (!(cin >> choice)) {
            cout << "Invalid input! Enter number 0-3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1: task1(); break;
        case 2: task_2(); break;
        case 3: task_series(); break;
        case 0: cout << "Exiting program...\n"; break;
        default: cout << "Invalid choice! Choose 0-3.\n";
        }
    } while (choice != 0);

    return 0;
}
