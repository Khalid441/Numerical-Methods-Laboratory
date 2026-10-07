#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    m++;                      
  vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    double xn;
    cin >> xn;

    // ১. matrix
    double A[20][21] = {};
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < m; k++)
            for (int i = 0; i < n; i++)
                A[j][k] += pow(x[i], j + k);
        for (int i = 0; i < n; i++)
            A[j][m] += pow(x[i], j) * y[i];
    }

    // ২. Gauss elimination
    for (int c = 0; c < m; c++) {
        int p = c;
        for (int r = c + 1; r < m; r++)
            if (fabs(A[r][c]) > fabs(A[p][c])) p = r;
        for (int k = 0; k <= m; k++) swap(A[c][k], A[p][k]);

        for (int r = c + 1; r < m; r++) {
            double f = A[r][c] / A[c][c];
            for (int k = c; k <= m; k++)
                A[r][k] -= f * A[c][k];
        }
    }

    // ৩. Back substitution
    double a[20];
    for (int i = m - 1; i >= 0; i--) {
        double s = A[i][m];
        for (int j = i + 1; j < m; j++) s -= A[i][j] * a[j];
        a[i] = s / A[i][i];
    }

    // ৪. Print
    cout << "f(x) = ";
    for (int i = 0; i < m; i++) {
        if (i > 0 && a[i] >= 0) cout << "+";
        cout << a[i] << "x^" << i << " ";
    }

    double ans = 0;
    for (int i = 0; i < m; i++) ans += a[i] * pow(xn, i);
    cout << "\nf(" << xn << ") = " << ans << "\n";
}
