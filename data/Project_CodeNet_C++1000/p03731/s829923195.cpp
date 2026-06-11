#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;

int main(){
    int N, T;
    cin >> N >> T;
    vector<int> t(N);
    rep(i, N) cin >> t[i];
    ll ans = T;
    for (int i=1; i<N; i++) {
        ans += min(T, t[i]-t[i-1]);
    }
    cout << ans << endl;
    return 0;
}