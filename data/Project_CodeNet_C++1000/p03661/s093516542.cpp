#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> a(N);
    for(auto& in:a) cin >> in;
    ll res = LINF;
    vector<ll> cusum(N,0);
    cusum[0] = a[0];
    for(int i = 1; i < N;i++){
        cusum[i] = cusum[i-1] + a[i];
    }
    for(int i = 0; i < N-1;i++){
        res = min(res,abs(cusum[i] - (cusum[N-1] - cusum[i])));
    }
    cout << res << endl;
    return 0;
}