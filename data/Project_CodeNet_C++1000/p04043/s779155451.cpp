#include <bits/stdc++.h>
using namespace std;

int main(){
   vector<int> a(3);
   cin >> a.at(0) >> a.at(1) >> a.at(2);
   sort(a.begin(), a.end());
   if(a.at(0) == 5 && a.at(1)== 5 && a.at(2) == 7) cout << "YES\n";
   else cout << "NO\n";
   return 0;
}