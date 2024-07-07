#include <bits/stdc++.h>
using namespace std;
#define e 0.0001

double func(double x){
    return 3*x - cos(x) -1;
}

double der_func(double x){
    return 3 + sin(x);
}

double horners(double arr[], double size, double point){
    double result = arr[0];
    for(int i = 0; i<size; i++){
        result = result*point + arr[i];
    }
    return result;
}

void newtonRaphson(double x0){
    double f1, x1, count = 0;
    
    do
    {
        if (der_func(x0) == 0){
            cout << "Mathematical error";
            exit(0);
        }
        x1 = x0 - func(x0)/der_func(x0);
        x0 = x1;
        f1 = func(x1); 
    
    } while (fabs(f1)>e);

    cout<<"The root is: "<<x1<<endl;

    double arr[] = {3, -1, -1};
    double point = x1;
    double size = sizeof(arr)/sizeof(arr[0]);

    cout<<"After horner's evaluation: "<<horners(arr, size, point)<<endl;
    for (int j = 0; j<size; j++){
        cout<<"term ^ "<<j<<" = "<<arr[j]<<endl;
    }
}

int main(){
    double x = 2;
    newtonRaphson(x);
    return 0;
}