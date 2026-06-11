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
   if(t!=1) cout << max(c-1-(k-c),0) << endl;
   else cout << c-1 << endl;
}