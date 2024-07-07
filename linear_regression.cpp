#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,j;
    cout<<"Input the number of data points: ";
    cin>>n;

    double x[n], y[n], sumx=0,sumx2=0,sumy=0,sumxy=0,a,b;
    for(i=1; i<=n; i++){
        cout<<"Enter x["<<i<<"] and y["<<i<<"] : ";
        cin>>x[i]>>y[i];
    }

    for(i=1;i<=n;i++){
        sumx= sumx+x[i];
        sumx2 = sumx2 + x[i]*x[i];
        sumy= sumy + y[i];
        sumxy =sumxy + x[i]*y[i];
    }

    b=(n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
    a=(sumy-b*sumx)/n;

    cout<<"a= "<<a<<" and b= "<<b;

    return 0;
}
