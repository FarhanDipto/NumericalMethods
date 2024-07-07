#include <bits/stdc++.h>
using namespace std;
#define e 0.0001

double f(double x){
    return x * x * x * x * x + 7 * x * x * x - 3 * x - 12;
}

void r(double a, double b){
    double x1, x2, xr, ds = 1;
    // int count = 0;

    while (x2 < b){
        x1 = a;
        x2 = x1 + ds;

        if (f(x1) * f(x2) > 0){
            cout << "wrong guesses";
            break;
        }

        else{
            do{
                xr = (x1 + x2) / 2;

                if ((f(x1) * f(xr)) < 0){
                    x2 = xr;
                }
                else{
                    x1 = xr;
                }

            } while (fabs((x2 - x1) / x2) >= e);

            cout<<"The root is: "<<xr<<endl;
            //Insert count related code here

            if (x2 > b){
                break;
            }
        }
        a=x2;
    }
}

int main(){
    double a = 0, b = 12;
    r(a,b);
}