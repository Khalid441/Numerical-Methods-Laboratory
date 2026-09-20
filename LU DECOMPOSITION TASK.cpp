#include <bits/stdc++.h>
using namespace std;
const double eps =0.0001;
const int mx=20;
int n;
double A[mx][mx],L[mx][mx],U[mx][mx];
double B[mx],Z[mx],X[mx];
void solve ()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            L[i][j]=0;
            U[i][j]=0;
        }
        L[i][i]=1;
    }
    int badr=-1;
    bool singular=false;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            double sum=0;
            for(int k=0; k<i; k++)
            {
                sum+=L[i][k]*U[k][j];
            }
            U[i][j]=(A[i][j]-sum);
        }
        if(fabs(U[i][i])<eps&&!singular)
        {
            singular=true;
            badr=i;
        }
        for(int j=i+1; j<n; j++)
        {
            double sum=0;
            for(int k=0; k<i; k++)
            {
                sum+=L[j][k]*U[k][i];
            }
            if(fabs(U[i][i])<eps)
            {
                L[i][j]=0;
            }
            else L[j][i]=(A[j][i]-sum)/U[i][i];
        }
    }
    cout<<fixed<<setprecision(3);
    cout<<"L:"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }
        cout<<"U:"<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<U[i][j]<<" ";
        }
        cout<<endl;
    }
    if(singular)
    {
        for(int j=0; j<=badr; j++)
        {
            double sum=0;
            for(int k=0; k<n; k++)
            {
                sum+=L[j][k]*Z[k];
            }
            Z[j]=B[j]-sum;
        }
        double rowsum=0;
        for(int i=badr; i<n; i++)
        {
            rowsum+=fabs(U[badr][i]);
        }
        if(rowsum<eps&&fabs(Z[badr])<eps)
        {
            cout<<"this has infinite soln"<<endl;
        }
        else cout<<"this has no soln"<<endl;
        return;
    }
    // forward
    for(int i=0; i<n; i++)
    {
        double sum=0;
        for(int k=0; k<n; k++)
        {
            sum+=L[i][k]*Z[k];
        }
        Z[i]=B[i]-sum;
    }
    for(int i=n-1; i>=0; i--)
    {
        double sum=0;
        for(int k=i+1; k<n; k++ )
        {
            sum+=U[i][k]*X[k];
        }
        X[i]=(Z[i]-sum)/U[i][i];
    }
    cout<<"Solutions X[i]:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<X[i]<<" ";
    }
    cout<<"\nunique solution"<<endl;
}
int main()
{
    char ch;
    do
    {
        cout<<"Enter no of equation"<<endl;
        cin>>n;
        cout<<"Enter the augmented matrix"<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>A[i][j];
            }
            cin>>B[i];
            Z[i]=0;
            X[i]=0;
        }
        solve();
        cin>>ch;
        cout<<"Solve another system (y/n)?"<<endl;
    }
    while(ch=='y');

}
