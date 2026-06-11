#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;

int main() {
  string S; cin >> S;
  int n = S.size();
  ll ans = 0;
  rep(bit,(1<<n-1)){
    ll sum = 0;
    rep(i,n){
      sum *= 10;
      sum += S[i] -'0';
      if(bit & 1<<i){
        ans += sum;
        sum = 0;
      }
    }
    ans += sum;
  }

  cout << ans << endl;
	return 0;
}

