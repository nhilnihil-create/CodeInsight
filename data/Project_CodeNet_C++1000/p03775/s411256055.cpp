#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(void) {
ll N;
cin >> N;
ll ans = INF;
for (ll i = 1;i <= sqrt(N);i++) {
string s,t;
if (N % i == 0) {
    ll cnt;
    s = std::to_string(i);
    t = std::to_string(N/i);
    cnt = max(s.size(),t.size());
    ans = min(ans,cnt);
}
}
cout << ans << endl;

return 0;
}



