#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,i,j,k;
    cout<<"Enter the order of the matrix: ";
    cin>>n;

    double a[n+1][n+1], x[n+1], t[n+1];
    double sum, error, te=0.00001, e;

    cout<<"Input the coefficients: ";
    for(i=1; i<=n; i++){
        cout<<"Eqn "<<i<<": ";
        for(j=1; j<=n+1; j++){ 
            cin>>a[i][j];
        }
    }

    for(i=1;i<=n;i++)
        x[i]=0;

    do
    {
        e=0;
        for(i=1;i<=n;i++){
            sum=0;
            for(j=1;j<=n;j++){
                if(i!=j){
                    sum+=a[i][j]*x[j];
                }
            }
            t[i]=(a[i][n+1]-sum)/a[i][i];
            error = fabs(x[i]-t[i]);

            if(error>e){
                e = error;
            }
        }
        for(i=1;i<=n;i++){
            x[i]=t[i];
        }

    }while(e>=te);

    for(i=1; i<=n; i++){
        cout<<"x"<<i<<" = ";
        cout<<x[i]<<endl;
    }

    return 0;
}

