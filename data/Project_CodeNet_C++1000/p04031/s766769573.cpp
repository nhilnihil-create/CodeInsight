#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> a(N);
    rep(i, N){
        cin >> a[i];
    }

    ll ans = 1001001001;
    for (int i = -100; i < 101; i++){
        ll now = 0;
        for (int j = 0; j < N; j++){
            int c = abs(i-a[j]);
            c *= c;
            now += c;
        }
        ans = min(ans, now);
    }

    cout << ans << endl;

    return 0;
}