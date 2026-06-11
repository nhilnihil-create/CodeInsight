#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;


int main() {
  string S; cin >> S;
  int n = S.size();
  ll ans = 0;
  rep(bit, (1<<n-1)){
    ll sum = 0;
    rep(i,n){
      if(bit &(1<<i-1)){
        ans += sum;
        sum = S[i] - '0';
      } else {
        sum = sum * 10 + S[i] -'0';
      }
    }
    ans += sum;
  }
  cout << ans << endl;
	return 0;
}

