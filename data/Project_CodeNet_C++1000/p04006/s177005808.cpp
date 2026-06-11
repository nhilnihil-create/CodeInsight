#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N,x,sum = 0;
    cin >> N >> x;
    vector<ll> a(N);
    rep(i,N){
        cin >> a[i];
        sum += a[i];
    }
    vector<ll> mn = a;
    ll ans = sum;
    rep(i,N+1){
        ll t = i * x;
        // i 回魔法を使うとすると各jについて
        rep(j,N){
            mn[j] = min(mn[j],a[(j - i + N) % N]);
            t += mn[j];
        }
        ans = min(ans,t);
    }
    cout << ans << endl;
}