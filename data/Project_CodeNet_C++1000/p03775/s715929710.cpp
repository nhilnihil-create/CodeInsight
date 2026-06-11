#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    ll N; cin >> N;
    int ans = 1000;
    for (ll i = 1; i*i <= N; i++){
        if(N % i != 0)continue;
        ll big = N / i;
        string s = to_string(big);
        int ss = s.size();
        ans = min(ans, ss);
    }

    cout << ans << endl;

    return 0;
}