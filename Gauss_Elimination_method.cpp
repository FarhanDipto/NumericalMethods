#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,i,j,k;
    cout<<"Enter the order of the matrix: ";
    cin>>n;

    double a[n+1][n+1], x[n+1], sum, temp;

    cout<<"Input the coefficients: ";
    for(i=1; i<=n; i++){
        cout<<"Eqn "<<i<<": ";
        for(j=1; j<=n+1; j++){ 
            cin>>a[i][j];
        }
    }

    for(k=1;k<=n-1;k++){
        for(i=k+1;i<=n;i++){
            temp = a[i][k]/a[k][k];
            for(j=1;j<=n+1;j++){
                a[i][j]=a[i][j]-temp*a[k][j];
            }
        }
    }

    x[n]=a[n][n+1]/a[n][n];

    for(k=n-1;k>=1;k--)
    {
        x[k]=a[k][n+1];
        for(j=k+1;j<=n;j++)
        {
            x[k]=x[k]-a[k][j]*x[j];
        }
        x[k]=x[k]/a[k][k];
    }

    for(i=1; i<=n; i++){
        cout<<"x"<<i<<" = ";
        cout<<x[i]<<endl;
    }

    return 0;
}
