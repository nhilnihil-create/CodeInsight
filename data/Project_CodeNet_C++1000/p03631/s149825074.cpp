#include <bits/stdc++.h>
using namespace std;
 int main() {
int a,b,c;
   cin >> a;
   int x,y,z;
   z = a/100;
   b = a%100;
   y = b/10;
   x = b%10;
   
   if(a==(100*x+10*y+z)) cout <<"Yes"<<endl;
   else cout <<"No"<<endl;
   }
   
