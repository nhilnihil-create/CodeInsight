#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    ll T;
    cin >> N >> T;;
    
    vector<ll> t(N);

    for(int i = 0; i < N; i++) {
        cin >> t[i];
    }

    ll ans = T;

    for(int i = 1; i < N; i++) {
        ans += min(t[i] - t[i - 1], T);
    }

    cout << ans << endl;
}