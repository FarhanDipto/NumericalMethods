#include <bits/stdc++.h>
using namespace std;
#define e 0.000001

double fx(double x){
    return cos(x) - 3*x + 1;
}

double gx(double x){
    return (1+cos(x)) / 3;
}

double horners(double arr[], double size, double point){
    double result = arr[0];
    for(int i = 0; i<size; i++){
        result = result*point + arr[i];
    }
    return result;
}

void fixedPoint(double x){
    double root, step = 1, N;
    cout<<"Enter maximum iteration: ";
    cin>>N;
    cout<<endl;

    do{
        root = gx(x);  
        step++;

        if(step>N){
            cout<<"Not convergent";
            exit(0);
        }
        x=root;  
    }while(fabs(fx(root))>e);

    cout<<"The root is: "<<root;

    double arr[] = {1, -3, 1};
    double point = root;
    double size = sizeof(arr)/sizeof(arr[0]);

    cout<<"After horner's evaluation: "<<horners(arr, size, point)<<endl;
    for (int j = 0; j<size; j++){
        cout<<"term ^ "<<j<<" = "<<arr[j]<<endl;
    }
}

int main(){
    double x = 1;
    fixedPoint(x);
}