#include<bits/stdc++.h>
using namespace std;

double func(double arr[],int n, double x)
{
    double result=0;
    for(int i=0; i<=n; i++)
        result=result*x+arr[i];
    return result;
}

double dfunc(double arr[],int n, double x)
{
    double result=0;
    for(int i=0; i<n; i++)
        result=result*x+(n-i)*arr[i];
    return result;
}
int main()
{
    int i, n=2;
    int temp =n;
    double x0, xr, te=0.0001, f1, brr[n], arr[n], e;

    cout<<"Enter the co-efficients:"<<endl;
    for(i=0; i<=n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter the initial estimate: "<<endl;
    cin>>x0;

        do
        {
            do
            {
                xr = x0 - (func(arr,n,x0)/dfunc(arr,n,x0));


                e=fabs(xr-x0);
                x0=xr;
            }
            while(e>te);

            // printf("%.6lf\n", x0);
            cout<<"Roots: "<<x0<<endl;
            brr[0]=arr[0];
            for(i=1; i<=n; i++)
            {
                brr[i]=arr[i]+brr[i-1]*xr;
            }
            n--;
            for(i=0; i<=n; i++)
                arr[i]=brr[i];

            x0=xr;
        }
        while(n>1);


    xr=-arr[0]/arr[1];
    printf("%.6lf\n", xr);

    return 0;
}