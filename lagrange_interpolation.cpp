#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Input the number of data points: ";
    cin>>n;

    double x[n], y[n], xp, yp=0, p;
    for(int i=0; i<n; i++){
        cout<<"Enter x["<<i+1<<"] and y["<<i+1<<"] : ";
        cin>>x[i]>>y[i];
    }
    cout<<"Enter the value of x at which point interpolation is required: ";
    cin>>xp;

    for (int i=0; i<n; i++){
        p=1;
        for (int j=0; j<n; j++){
            if (i!=j){
                p = p* (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp = yp + p * y[i];
    }
    cout<<"Interpolated function value at x: "<<xp<<" is "<<yp;
}