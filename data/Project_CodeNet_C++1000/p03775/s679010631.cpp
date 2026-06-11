#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int cnt(ll  n){
  int d = 0;
  while(n > 0){
    n /= 10;
    d++;
  }
  return d;
}

int main(){
  ll n;
  cin >> n;

  int ans = cnt(n);

  for(ll a = 1LL; a*a <= n; a++){
    if(n%a != 0) continue;
    const ll b = n/a;

    const int cur = max(cnt(a), cnt(b));

    if(ans > cur){
      ans = cur;
    }
  }

  cout << ans << endl;
  return 0;
}



 