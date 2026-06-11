#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
   int n, m, a, b;
   cin >> n >> m;
   
   vector<int> x(n, 0);
   
   for(int i = 0; i < m*2; ++i){
       cin >> a;
       ++x.at(a-1);
   }
   
   for(int i = 0; i < n; ++i){
       cout << x.at(i) << endl;
   }
}
