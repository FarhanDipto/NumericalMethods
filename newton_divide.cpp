#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,j=1,n;
    cout<<"Input the number of data points: ";
    cin>>n;

    double x[n], y[n], xp, yp=0, p;
    for(i=1; i<=n; i++){
        cout<<"Enter x["<<i<<"] and y["<<i<<"] : ";
        cin>>x[i]>>y[i];
    }

    cout<<"Enter the value of x at which point interpolation is required: ";
    cin>>xp;

    yp=y[1];
    do{
        for (i=1; i<=n-1; i++){
            y[i] = ((y[i+1]-y[i])/(x[i+j]-x[i]));
        }
        p=1;
        for(i=1; i<=j; i++){
            p*=(xp-x[i]);
        }
        yp+=(y[1]*p);
        n--;
        j++;
    }while(n!=1);

    cout<<"Interpolated function value at x: "<<xp<<" is "<<yp;
}

