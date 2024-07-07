#include<bits/stdc++.h>
using namespace std;

int main() {

   double a[10][10], b[10], m[10], n[10];
   int p = 0, q = 0, i = 0, j = 0;

   cout << "Order of the matrix: ";
   cin >> p;

   cout<<"Enter the A matrix: ";
   for (i = 0; i < p; i++) {
      for (j = 0; j < p; j++) {
         cout << "a[" << i+1 << "," << j+1 << "]= ";
         cin >> a[i][j];
      }
   }

   cout<<endl;
   cout<<"Enter the B matrix: ";
   for (i = 0; i < p; i++) {
      cout << "b[" << i+1 << "," << j+1 << "]=";
      cin >> b[i];
   }

   cout <<"Enter initial values of x: ";
   for (i = 0; i < p; i++) {
      cout << "x:[" << i+1 <<"]= ";
      cin >> m[i];
   }
   
   cout <<"Max number of iteration: ";
   cin >> q;
   while (q> 0) {
      for (i = 0; i < p; i++) {
         n[i] = (b[i] / a[i][i]);
         for (j = 0; j < p; j++) {
            if (j == i)
               continue;
            n[i] = n[i] - ((a[i][j] / a[i][i]) * m[j]);
            m[i] = n[i];
         }
         cout<<"Iteration: "<<i+1<<endl;
         cout<<"x"<<i + 1 << "="<<n[i]<<" ";
      }
      cout <<endl;
      q--;
   }
   return 0;
}