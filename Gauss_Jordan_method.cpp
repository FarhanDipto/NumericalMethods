#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,i,j,k;
    cout<<"Enter the order of the matrix: ";
    cin>>n;

    double a[n+1][n+1], x[n+1], sum, pivot;

    cout<<"Input the coefficients: ";
    for(i=1; i<=n; i++){
        cout<<"Eqn "<<i<<": ";
        for(j=1; j<=n+1; j++){ 
            cin>>a[i][j];
        }
    }


    for(i=1; i<=n; i++){

        if(a[i][i]==0.0){
            cout<<"Mathematical Error!"<<endl;
            return 0;
        }
        for(j=1; j<=n; j++){

            if(i!=j){
                pivot = a[j][i]/a[i][i];
                for(k=1; k<=n+1; k++)
                {
                    a[j][k]=a[j][k]-pivot*a[i][k];
                }
            }
        }
    }

    for(i=1; i<=n; i++){
        x[i]=a[i][n+1]/a[i][i];
    }


    for(i=1; i<=n; i++){
        cout<<"x"<<i<<" = ";
        cout<<x[i]<<endl;
    }

    return 0;
}

