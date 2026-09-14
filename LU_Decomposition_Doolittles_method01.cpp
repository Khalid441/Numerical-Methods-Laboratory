#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

vector <vector <ld>> a, l, u;
vector <ld> b, z, x;
ll n;
ld eps = 1e-9;

int main() {
    cin >> n;

    a.assign(n, vector <ld> (n, 0));
    l.assign(n, vector <ld> (n, 0));
    u.assign(n, vector <ld> (n, 0));
    
    b.assign(n, 0);
    z.assign(n, 0);
    x.assign(n, 0);

    for(auto &vec : a) {
        for(auto &val : vec) {
            cin >> val;
        }
    }

    for(auto &val : b) {
        cin >> val;
    }

    for(ll i = 0; i < n; ++i) {
        l[i][i] = 1; // l[i][i] = 1, not u[i][i]; 
    }


    for(ll j = 0; j < n; ++j) { // j first
        for(ll i = 0; i < n; ++i) { // i second
            ld sum = 0;
            for(ll k = 0; k < n; ++k) {
                sum += l[i][k] * u[k][j];
            }

            if(i > j) {
                l[i][j] = (a[i][j] - sum) / u[j][j]; // u[j][j], not u[i][i]
            }
            else {
                u[i][j] = a[i][j] - sum;
            }
        }
    }

    for(ll i = 0; i < n; ++i) {
        if(abs(u[i][i]) < eps) {
            cerr << "\nNot solvable using LU Decomposition.\n";
            return 0;
        }
    }

    for(ll i = 0; i < n; ++i) {
        ld sum = 0;
        for(ll j = 0; j < n; ++j) {
            sum += l[i][j] * z[j];
        }

        z[i] = b[i] - sum;
    }

    for(ll i = n - 1; i > -1; --i) {
        ld sum = 0;
        for(ll j = n - 1; j > -1; --j) {
            sum += u[i][j] * x[j];
        }

        x[i] = (z[i] - sum) / u[i][i];
    }

    cout << '\n';
    for(auto &val : x) {
        cout << val << ' ';
    }

    cout << '\n';
}

/*
3
2 3 1
1 2 3
3 1 2
9 6 8

4
4 5 6 7
3 7 9 -2
10 -3 -5 -6
0 8 8 -1    
12 45 1 -6

4
4 5 6 7
3 7 9 -2
10 -3 -5 -6
-20 6 10 12    
12 45 1 -6

*/