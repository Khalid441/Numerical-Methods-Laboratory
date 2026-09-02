#include <bits/stdc++.h>
using namespace std;
#define EPSILON 0.0001
#define steps 0.5

double a, b, c, d, e;
double func(double x)
{
    return a * x * x * x * x + b * x * x * x + c * x * x + d * x + e;
}
double bisection(double x1, double x2, int &iteration)
{
    iteration = 0;
    while (abs(func(x1) - func(x2)) >= EPSILON)
    {
        double x0 = (x1 + x2) / 2;
        iteration++;
        if (abs(func(x0)) < EPSILON)
        {
            return x0;
        }
        else if (func(x1) * func(x0) < 0)
        {
            x2 = x0;
        }
        else
        {
            x1 = x0;
        }
    }
    return (x1 + x2) / 2;
}

int main()
{
    cin >> a >> b >> c >> d >> e;
    double xmax = sqrt(pow((b / a), 2) - 2 * (c / a));
    double x1 = -xmax;
    double x2 = x1 + steps;
    int rootCount = 0;

    while (x2 < xmax)
    {
        if (func(x1) * func(x2) < 0)
        {
            int iteration;
            rootCount++;
            double root = bisection(x1, x2, iteration);
            cout << rootCount << " root : " << root << endl;
            cout << "Search interval of " << rootCount << " root : " << "[" << x1 << "," << x2 << "]" << endl;
            cout << "Iteration needed for " << rootCount << " root : " << iteration << endl;
        }

        x1 += steps;
        x2 += steps;
    }
}
