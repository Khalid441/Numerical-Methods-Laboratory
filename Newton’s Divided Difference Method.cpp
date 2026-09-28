#include<bits/stdc++.h>
using namespace std;

int main(){

    cout<<"Enter num of data points: ";
    int n;
    cin>>n;

    cout<<"Enter x values:\n";
    vector<double> xs(n);
    for(int i=0;i<n;i++)
        cin>>xs[i];

    cout<<"Enter y values:\n";
    vector<double> ys(n);
    for(int i=0;i<n;i++)
        cin>>ys[i];

    cout<<"Enter value to be interpolated:\n";
    double x;
    cin>>x;


    // Divided Difference Table
    vector<vector<double>> ddiff(n, vector<double>(n));

    for(int i=0;i<n;i++)
        ddiff[i][0]=ys[i];

    for(int j=1;j<n;j++){
        for(int i=0;i+j<n;i++){
            ddiff[i][j] =
                (ddiff[i+1][j-1]-ddiff[i][j-1])
                /(xs[i+j]-xs[i]);
        }
    }


    // Interpolation using first n-1 points
    double ans=ys[0];
    double prod=1;

    for(int i=1;i<n-1;i++){
        prod *= (x-xs[i-1]);
        ans += ddiff[0][i]*prod;
    }


    // Display table
    cout<<"\nDivided Difference Table:\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++)
            cout<<fixed<<setprecision(6)
                <<setw(10)<<ddiff[i][j];

        cout<<endl;
    }


    cout<<"\nInterpolated value at x="
        <<x<<" is "<<ans<<endl;


    // Last point is treated as an additional point
    cout<<"\nConsidering last point as extra point\n";

    // Product (x-x0)(x-x1)...(x-x(n-2))
    double errorProduct=1;

    for(int i=0;i<n-1;i++)
        errorProduct *= (x-xs[i]);


    // Error = nth divided difference * product
    double err=ddiff[0][n-1]*errorProduct;

    cout<<"Truncation error: "<<err<<endl;

    return 0;
}
