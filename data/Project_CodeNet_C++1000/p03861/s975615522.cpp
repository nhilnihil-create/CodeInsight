#include <bits/stdc++.h>
using namespace std;
int main(){
   long long a,b,c;
   cin >> a >> b >> c;
   long long x = a/c;
   long long y = b/c;
   long long z = y-x;
   if(a%c == 0)z++;
   cout << z << endl;
   return 0;
}
