#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   string s; cin >> s;
   bool N, W, S, E;
   N=W=S=E=false;
   for (auto &&i : s){
      switch (i){
      case 'N':N=true;break;
      case 'W':W=true;break;
      case 'S':S=true;break;
      case 'E':E=true;break;
      }
   }
   if ((N==S)&&(W==E))cout << "Yes" << endl;
   else cout << "No" << endl;
}