#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N, K;
    cin >> N >> K;

    int l[N];
    rep(i, N) cin >> l[i];
    sort(l, l+N, greater<int>());

    int ans = 0;
    for (int i = 0; i < K; ++i) {
        ans += l[i];
    }
    
    cout << ans << endl;


    return 0;
}