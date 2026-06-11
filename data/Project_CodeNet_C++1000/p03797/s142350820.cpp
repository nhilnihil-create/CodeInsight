#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
  ll n,m;
  cin >> n >> m;
  ll ans = 0;
  if(n * 2 >= m){
    ll temp = m / 2;
    n -= temp;
    m -= temp * 2;
    ans += temp;
  }else{
    ans += n;
    m -= n * 2;
  }
  ans += m / 4;
  cout << ans << endl;
}