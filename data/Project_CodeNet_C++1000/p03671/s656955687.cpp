#include <bits/stdc++.h>
using namespace std;
 int main() {
int a,b,c;
   cin >> a>>b>>c;
   int sum =1000000;
   sum = min(sum,a+b);
   sum = min(sum,a+c);
   sum = min(sum,c+b);
   
cout << sum <<endl;
     
   }
   
