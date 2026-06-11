#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;
ll cnt[26];
int main() {
    string A; cin >> A;
    ll len = A.length();
    rep(i,len) cnt[A[i]-'a']++;
    ll ans = len * (len - 1) / 2;
    rep(i,26) {
      if(cnt[i] >= 2) {
        ans -= cnt[i] * (cnt[i] - 1) / 2;
      }
    }
    cout << ans + 1 << endl;
    return 0;
}