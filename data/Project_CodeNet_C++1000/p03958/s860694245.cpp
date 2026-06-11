#include <bits/stdc++.h>
using namespace std;
int main(){
   int k,t,c=0;
   cin >> k >> t;
   for(int i=0;i<t;i++){
       int a;
       cin >> a;
       c = max(a,c);
   }
   cout << max(2*c-1-k,0) << endl;
}