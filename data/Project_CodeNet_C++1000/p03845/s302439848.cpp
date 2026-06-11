#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

   int n;
   cin >> n;
   vector<int> t(n + 1);
   int total_time = 0;
   for(int i = 1; i <= n; i++){
     cin >> t[i];
     total_time += t[i];
   }

   int m;
   cin >> m;
   
   for(int i = 0; i < m; i++){
       int p, x;
       cin >> p >> x;
       cout << (total_time - t[p] + x) << endl;
   }
   
   return 0;
}
