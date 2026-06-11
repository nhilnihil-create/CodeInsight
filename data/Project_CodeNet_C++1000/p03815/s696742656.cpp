#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;


int main() {
     ll x;
     cin >> x;
     if (x%11==0){
     cout << x/11*2 <<endl;
     return 0;}
     else if(x%11<7){cout << x/11*2+1;
     return 0;}
     else cout << x/11*2+2<<endl;
  }