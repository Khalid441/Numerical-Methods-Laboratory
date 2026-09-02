#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x*x*x*x - 5*x*x + 4;
}

double falsep(double a, double b, double e, int &it)
{
    double c;
    it = 0;

    while (true)
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        it++;

        if (fabs(f(c)) < e)
            break;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    return c;
}

int main()
{
    double start = -4.0;
    double en = 4.0;
    double step = 0.5;
    double e = 0.0001;

    double a = start;

    while (a < en)
    {
        double b = a + step;

        double fa = f(a);
        double fb = f(b);

        // Check if a itself is a root
        if (fabs(fa) < e)
        {
            cout << "Root: " << a << endl;
            cout << "Search interval = [" << a << ", " << b << "]" << endl;
            cout << endl;
        }
        // Check if b itself is a root
        else if (fabs(fb) < e)
        {
            cout << "Root: " << b << endl;
            cout << "Search interval = [" << a << ", " << b << "]" << endl;
            cout << endl;
        }
        // Normal false-position case
        if (fa * fb < 0)
        {
            int it;
            double root = falsep(a, b, e, it);

            cout << "Root: " << root << endl;
            cout << "Search interval = [" << a << ", " << b << "]" << endl;
            cout << "Iterations = " << it << endl;
            cout << endl;
        }

        a = b;
    }

    return 0;
}
