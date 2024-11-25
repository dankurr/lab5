#include <iostream>
using namespace std;


void checkValidInput()
{
    if (cin.fail())
    {
        throw "Incorrect input";
    }
}

void checkValidParams(double n, double h)
{
    if (n - 1 < 1)
    {
        throw "Input correct data for n";
    }
    if (h <= 0)
    {
        throw "Input correct data for h";
    }
}

double calculate(double x, double n)
{
    double y;
    if (x > 0) {
        y = 1;
        for (double i = 1; i <= n; i++) {
            y *= (1 / x) - (1 / i);
        }
    }
    else {
        y = 0;
        for (int i = 0; i <= n - 1; i++) {
            double s = 0;
            for (int j = 0; j <= n - 1; j++) {
                s += 1 / (x - i + x * j);
            }
            y += s;
        }
    }
    return y;
}

int main()
{
    double a, b, h, n;

    try
    {
        cout << "Enter a: ";
        cin >> a;
        checkValidInput();

        cout << "Enter b: ";
        cin >> b;
        checkValidInput();

        cout << "Enter step h > 0: ";
        cin >> h;
        checkValidInput();

        cout << "Enter n >= 2: ";
        cin >> n;
        checkValidInput();

        checkValidParams(n, h);
    }
    catch (const char* ex)
    {
        cout << ex << endl;
        return -1;
    }
    catch (...)
    {
        cout << "Unknown error" << endl;
        return -2;
    }

    for (double x = a; x <= b; x += h)
    {
        double y = calculate(x, n);
        cout << "x = " << x << ", y = " << y << endl;
    }

    return 0;
}
