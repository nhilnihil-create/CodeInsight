#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> T(N);
    for(int i=0; i<N; i++) cin >> T[i];

    ll ans = 1;
    for(int i=0; i<N; i++) ans = lcm(ans, T[i]);

    cout << ans << endl;

    return 0;
}
