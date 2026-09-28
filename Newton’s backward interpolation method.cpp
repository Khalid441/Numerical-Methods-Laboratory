#include<bits/stdc++.h>
using namespace std;

double fact(int n){
    double f = 1.0;
    for (int i=2; i<=n; i++) f*=i;
    return f;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cout<<"Enter num of data points: ";
    int n; cin>>n;

    cout<<"Enter x values: ";
    vector<double> xs(n);
    for (int i=0; i<n; i++) cin>>xs[i];

    cout<<"Enter y values: ";
    vector<double> ys(n);
    for (int i=0; i<n; i++) cin>>ys[i];
    
    cout<<"Enter value to be interpolated: ";
    double x; cin>>x;
    
    //Backward difference table
    vector<vector<double>> diff(n, vector<double>(n, 0.0));
    for (int i=0; i<n; i++) diff[i][0]=ys[i];
    for (int j=1; j<n; j++){
        for (int i=n-1; i>0; i--){
            diff[i][j] = diff[i][j-1] - diff[i-1][j-1];
        }
    }
    
    double h=xs[1]-xs[0];
    double v=(x-xs[n-1])/h;

    //backward interpolation
    double ans=diff[n-1][0];
    double v_prod=1;
    for (int k=1; k<n; k++){
        v_prod *= (v+(k-1));
        ans += (v_prod/fact(k))*diff[n-1][k];
    }

    cout<<fixed<<setprecision(2);
    cout<<"\nBackward Difference Table:\n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<setw(5)<<diff[i][j]<<" ";
        }
        cout<<'\n';
    }

    cout<<"\nInterpolated value at x = "<<x<<" is f(x) = "<<ans<<"\n";
    return 0;
}
