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

double secant(double x0, double x1, int &iteration)
{
    iteration = 0;
    while (true)
    {
        double x2 = x1 - (func(x1) * (x1 - x0)) / (func(x1) - func(x0));
        iteration++;
        double error = fabs((x2 - x1) / x2);

        if (fabs(error) < EPSILON)
        {
            return x2;
        }

        x0 = x1;
        x1 = x2;
    }
}

int main()
{

    // input
    cout << "Number of the degree of the Equation : ";
    cin >> n;
    cout << "Coefficient of the Euqation : ";
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<"x^"<<n-i<<"  +  "<<" ";
    }
    cout<<a[n]<<endl;

    // range
    double max = 0;
    for (int i = 1; i <= n; i++)
    {
        double t = fabs(a[i] / a[0]);
        if (t > max)
        {
            max = t;
        }
    }

    double xmax = max + 1;
    double x1 = -xmax;
    double x2 = x1 + steps;
    int rootCount = 0;
    while (x2 <= xmax)
    {
        if (func(x1) * func(x2) < 0)
        {
            rootCount++;
            int iteration;
            double root = secant(x1, x2, iteration);

            cout << "Root Count : " << rootCount << endl;

            cout << "Root : " << root << endl;

            cout << "Interval : " << "[" << x1 << "," << x2 << "]" << endl;

            cout << "Iteration : " << iteration;
            cout << endl;
        }
        else if (fabs(func(x1)) < EPSILON)
        {
            rootCount++;

            cout << "Root Count : " << rootCount << endl;

            cout << "Root : " << x1 << endl;

            cout << "Interval : " << "[" << x1 << "," << x2 << "]" << endl;
            cout << "Iteration : 0";
            cout << endl;
        }
        x1 += steps;
        x2 += steps;
    }
}

/*
INPUT:
Number of the degree of the Equation : 4
Coefficient of the Euqation : 1 0 -5 0 4

OUTPUT:
1x^4  +   0x^3  +   -5x^2  +   0x^1  +   4
Root Count : 1
Root : -2
Interval : [-2,-1.5]
Iteration : 0
Root Count : 2
Root : -1
Interval : [-1,-0.5]
Iteration : 0
Root Count : 3
Root : 1
Interval : [1,1.5]
Iteration : 0
Root Count : 4
Root : 2
Interval : [2,2.5]
Iteration : 0*/
