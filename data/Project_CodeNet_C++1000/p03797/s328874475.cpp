#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;

    if(N >= M / 2LL) {
        cout << M / 2LL << endl;
        return 0;
    }

    ll ans = N;

    M -= N * 2LL;

    ans += M / 4LL;

    cout << ans << endl;
}