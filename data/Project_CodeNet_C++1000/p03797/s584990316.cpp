#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 1e6;
int t[5][5];
ll h,a,b,c,d,e;
int ans = 1;
ll mod = 1e9+7;
bool memo[15][15] = {0};
int main(){
  ll m,n;
  cin >> n >> m;
  ll ans = 0;
  if(n >= m/2){
    ans = m/2;
  }else{
    m -= 2*n;
    ans = n + m/4;
  }
  cout << ans << endl;
  return 0;
}
