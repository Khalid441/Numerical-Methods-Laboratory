#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

// y = P(z^q)ln(z)

int main() {
    ll n;
    cin >> n;

    vector<ld> z(n), y(n);

    for(ll i = 0; i < n; ++i) {
        cin >> z[i] >> y[i];

        // Transformation
        z[i] = logl(z[i]);
        y[i] = logl(y[i] / expl(z[i]));
    }

    ld sigX = 0;
    ld sigY = 0;
    ld sigXY = 0;
    ld sigXsq = 0;

    for(ll i = 0; i < n; ++i) {
        sigX += z[i];
        sigY += y[i];
        sigXY += z[i] * y[i];
        sigXsq += z[i] * z[i];
    }

    // q = slope
    ld q = (n * sigXY - sigX * sigY) /
           (n * sigXsq - sigX * sigX);

    // ln(P) = intercept
    ld lnP = (sigY - q * sigX) / n;

    // P = e^(lnP)
    ld P = expl(lnP);

    ld zNew;
    cin >> zNew;

    cout << "f(z) = " << P << "(z^" << q << ")ln(z)\n";

    cout << "f(" << zNew << ") = "
         << P * powl(zNew, q) * logl(zNew) << '\n';
}
