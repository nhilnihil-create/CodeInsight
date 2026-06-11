#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll N, T; cin >> N >> T;
    vector<ll> t(N);
    rep(i, N) cin >> t[i];

    ll time = 0;
    rep(i, N) {
        if (i == N - 1) time += T;
        else {
            time += min(T, t[i+1] - t[i]);
        }
    }
    cout << time << endl;

    return 0;
}