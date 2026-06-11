#include <bits/stdc++.h>
using namespace std;

int main() {
   int K,T;
   cin >> K >> T;
   int a[T];
   for (int i=0; i<T; i++) {
       cin >> a[i];
   }
   sort(a,a+T);
   int m=a[T-1];
   if (K%2==0) {
       if (m<=K/2) cout << 0 << endl;
       else {
           int n=m-K/2;
           cout << 2*n-1 << endl;
       }
   }
   else {
       if (m<=K/2+1) cout << 0 << endl;
       else {
           int n=m-K/2-1;
           cout << 2*n << endl;
       }
   }
}