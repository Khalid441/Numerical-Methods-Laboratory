#include <bits/stdc++.h>
using namespace std;

long double eps = 1e-3;

array <long double, 5> a;

long double eval(long double x) {
    long double val = 0;
    for(int i = 0; i < 5; ++i) {
        val += a[i] * powl(x, 4 - i);
    }

    return val;
}

pair <long double, int> bisect(long double x1, long double x2) {
    int cnt = 0;
    while(true) {
        long double x0 = (x1 + x2) / 2;
        long double fx1 = eval(x1);
        long double fx2 = eval(x2);

        if(abs(fx2 - fx1) < eps) {
            return {x0, cnt};
        }

        long double fx0 = eval(x0);

        if(fx0 == 0) {
            return {x0, cnt};
        }
        else if(fx1 * fx0 < 0) {
            x2 = x0;
        }
        else {
            x1 = x0;
        }

        ++cnt;
    }
}

int main() {
    for(auto &val : a) {
        cin >> val;
    }

    long double x2 = abs(sqrtl((a[1] / a[0]) * (a[1] / a[0]) - 2 * (a[2] / a[0])));
    long double x1 = -x2;

    long double temp = x1 + 0.5;
    while(temp < x2) {
        long double fx1 = eval(x1);
        long double ftemp = eval(temp);

        if(fx1 * ftemp < 0) {
            pair <long double, int> rt = bisect(x1, temp);
            cout << "Root: " << rt.first << "\nInterval: " << x1 << " and " << temp << '\n';
            cout << "Iterations: " << rt.second << "\n\n";
        }

        x1 += 0.5;
        temp += 0.5;
    }
}
