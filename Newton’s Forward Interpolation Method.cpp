#include<bits/stdc++.h>
using namespace std;

double fact(int n) {
    double f = 1.0;
    for (int i=2; i<=n; i++) f *= i;
    return f;
}

int main() {
  
    cout<<"Enter num of data points: ";
    int n; cin>>n;

    cout<<"Enter x values (ascending, equally spaced): ";
    vector<double> xs(n);
    for (int i=0; i<n; i++) cin>>xs[i];

    cout<<"Enter y values: ";
    vector<double> ys(n);
    for (int i=0; i<n; i++) cin>>ys[i];


    cout<<"Enter value to be interpolated: ";
    double x; cin >> x;

    //forward difference table
    vector<vector<double>> diff(n, vector<double>(n));
    for (int i=0; i<n; i++) diff[i][0] = ys[i];
    for (int j = 1; j < n; ++j) {
        for (int i=0; i+j<n; i++) {
            diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
        }
    }

    double h=xs[1]-xs[0];
    double u=(x-xs[0])/h;

    //Forward interpolation
    double ans=diff[0][0];
    double u_prod = 1.0;
    for (int k=1; k<n; ++k){
        u_prod *= (u-(k-1));
        ans += (u_prod/fact(k))*diff[0][k];
    }

    

    // Output
    cout<<fixed<<setprecision(2);
    cout<<"\nForward Difference Table:\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i; j++) {
            cout<<setw(12) << diff[i][j] << ' ';
        }
        cout<<'\n';
    }

    cout<<"\nInterpolated value at x = " << x << " f(x) = " << ans << "\n";
    return 0;
}
