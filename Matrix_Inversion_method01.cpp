#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define Matrix vector <vector <ld>>
using namespace std;

ld eps = 1e-9;

Matrix subMat(Matrix &a, ll r, ll c, ll n) {
    Matrix ans(n - 1, vector <ld> (n - 1));
    for(ll i = 0, p = 0; i < n; ++i) {
        if(i == r) {
            continue;
        }

        for(ll j = 0, q = 0; j < n; ++j) {
            if(j == c) {
                continue;
            }

            ans[p][q] = a[i][j];
            ++q;
        }

        ++p;
    }

    return ans;
}

ld det(Matrix &a, ll n) {
    if(n == 1) {
        return a[0][0];
    }

    ld ans = 0;
    for(ll i = 0; i < n; ++i) {
        Matrix sub = subMat(a, 0, i, n);

        if(i & 1LL) {
            ans -= a[0][i] * det(sub, n - 1);
        }
        else {
            ans += a[0][i] * det(sub, n - 1); 
        }
    }

    return ans;
}

Matrix adjoint(Matrix &a, ll n) {
    Matrix ans(n, vector <ld> (n));

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            Matrix sub = subMat(a, i, j, n);
            ld d = det(sub, n - 1);

            if((i + j) & 1LL) {
                ans[j][i] = -d;            
            }
            else {
                ans[j][i] = d;
            }
        }
    }

    return ans;
}

int main() {
    ll n;
    cin >> n;

    Matrix a(n, vector <ld> (n));
    for(auto &vec : a) {
        for(auto &val : vec) {
            cin >> val;
        }
    }

    vector <ld> b(n);
    for(auto &val : b) {
        cin >> val;
    }

    ld d = det(a, n);

    if(abs(d) < eps) {
        cerr << "\nInverse matrix does not exist. Hence, unsolvable by matrix inversion method.\n";
        return 1;
    }

    Matrix inv = adjoint(a, n);

    for(auto &vec : inv) {
        for(auto &val : vec) {
            val /= d;
        }
    }

    vector <ld> x(n);
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            x[i] += inv[i][j] * b[j];
        }
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