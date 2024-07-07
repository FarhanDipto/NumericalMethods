#include <bits/stdc++.h>
using namespace std;
#define e 0.0001

double func(double x){
    return  x*x*x - x -1;
}

double horners(double arr[], double size, double point){
    double result = arr[0];
    for(int i = 0; i<size; i++){
        result = result*point + arr[i];
    }
    return result;
}

void secant(double x1, double x2){

    double count = 0, xm, x3, c;
    if (func(x1) * func(x2) < 0) {
        do {
    
            x3 = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));
            x1 = x2;
            x2 = x3;

            count++;

            xm = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));

        } while (fabs(xm - x3) >= e); 
                                
 
        cout <<"The root is: "<<x3<<endl;
        cout << "No. of iterations = "<<count<<endl;
    } else
        cout << "Can not find a root in the given interval";

    double arr[] = {1, 0, -1, -1};
    double point = x3;
    double size = sizeof(arr)/sizeof(arr[0]);

    cout<<"After horner's evaluation: "<<horners(arr, size, point)<<endl;
    for (int j = 0; j<size; j++){
        cout<<"term ^ "<<j<<" = "<<arr[j]<<endl;
    }
}


int main(){
    double a = 1, b = 2;
    secant(a, b);

    return 0;
}