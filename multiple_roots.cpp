#include<bits/stdc++.h>
using namespace std;
#define esp 0.0001

double f(double arr[], int n, double x)
{
    double result=0;
    for(int i=0; i<=n; i++)
        result=result*x+arr[i];
    return result;
}

double fp(double arr[],int n, double x)
{
    double result=0;
    for(int i=0; i<n; i++)
        result=result*x+(n-i)*arr[i];
    return result;
}

int main(){
    int n, i, temp;
    cout<<"Enter the degree of the polynomial: ";
    cin>>n;
    temp = n;
    double x0, xr, f1, arr[n], brr[n], e;

    cout<<endl;
    cout<<"Enter the coefficients of the polynomial: ";
    for(i=0; i<=n; i++){
        cin>>arr[i];
    }

    cout<<endl;
    cout<<"Enter the initial estimate: "<<endl;
    cin>>x0;

    do
    {
        do
        {
            xr = x0 - (f(arr, n, x0) / fp(arr, n, x0));
            e = fabs(xr - x0);
            x0 = xr;
        }while (e > esp);

        cout << "Root: " << x0 << endl;
        
        brr[0] = arr[0];
        for (i = 1; i <= n; i++)
        {
            brr[i] = arr[i] + brr[i - 1] * x0;
        }
        n--;
        for (i = 0; i <= n; i++){
            arr[i] = brr[i];
        }
        // x0 = xr;
    } while (n > 1);

    xr = -arr[0] / arr[1];
    cout<<"Root: "<<xr;
}