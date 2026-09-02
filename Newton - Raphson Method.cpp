#include <bits/stdc++.h>
#define EPSILON 0.00001
#define steps 0.5
using namespace std;
int n;
double a[20];
double func(double x)
{
    double sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += a[i] * pow(x, n - i);
    }
    return sum;
}

double derivative(double x)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (n - i) * a[i] * pow(x, n - i - 1);
    }
    return sum;
}

double newtonRaphson(double x0, int &iteration)
{
    iteration = 0;
    while (true)
    {
        iteration++;
        double x1 = x0 - (func(x0) / derivative(x0));
        double error = fabs((x1 - x0) / x1);
        if (error < EPSILON)
        {
            return x1;
        }
        x0 = x1;
    }
}

int main()
{
    cout << "Degree of the equation : ";
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    double max = 0;
    for (int i = 1; i <= n; i++)
    {
        double t = fabs(a[i] / a[0]);
        if (t > max)
        {
            max = t;
        }
    }
    double xmax = max;
    double x1 = -xmax;
    double x2 = x1 + steps;

    int rootCount = 0;
    while (x2 <= xmax)
    {
        if (func(x1) * func(x2) < 0)
        {
            rootCount++;
            int iteration;
            double root = newtonRaphson(x1, iteration);
            cout << "Root : " << root << endl;
            cout << "Interval : " << "[" << x1 << "," << x2 << "]" << endl;
            cout << "Iteration : " << iteration << endl;
        }

        else if (fabs(func(x1)) < EPSILON)
        {
            rootCount++;
            cout << "Root : " << x1 << endl;
            cout << "Interval : " << "[" << x1 << "," << x2 << "]" << endl;
            cout << "Iteration : 0" << endl;
        }

        x1 += steps;
        x2 += steps;
    }
}

/*
Degree of the equation : 4
1 0 -5 0 4
Root : -2
Interval : [-2,-1.5]
Iteration : 0
Root : -1
Interval : [-1,-0.5]
Iteration : 0
Root : 1
Interval : [1,1.5]
Iteration : 0
Root : 2
Interval : [2,2.5]
Iteration : 0
*/
