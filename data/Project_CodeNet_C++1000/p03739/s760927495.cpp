#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
void Main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // +でstart
    vector<ll> S(n + 1);

    ll res = 1e18;
    ll sum = 0;
    rep(i, n) {
        if (i % 2 == 0) {
            // +でありたい
            if (S[i] + a[i] <= 0) {
                S[i + 1] = 1;
                sum += abs(S[i + 1] - (S[i] + a[i]));
            }
            else {
                S[i + 1] = S[i] + a[i];
            }
        }
        else {
            if (S[i] + a[i] >= 0) {
                S[i + 1] = -1;
                sum += abs(S[i + 1] - (S[i] + a[i]));
            }
            else {
                S[i + 1] = S[i] + a[i];
            }
        }
    }
    res = min(res, sum);

    
    sum = 0;
    rep(i, S.size()) S[i] = 0;
    rep(i, n) {
        if (i % 2 == 0) {
            // -でありたい
            if (S[i] + a[i] >= 0) {
                S[i + 1] = -1;
                sum += abs(S[i + 1] - (S[i] + a[i]));
            }
            else {
                S[i + 1] = S[i] + a[i];
            }
        }
        else {
            if (S[i] + a[i] <= 0) {
                S[i + 1] = 1;
                sum += abs(S[i + 1] - (S[i] + a[i]));
            }
            else {
                S[i + 1] = S[i] + a[i];
            }
        }
    }
    res = min(res, sum);

    put(res);
    
}
signed main(){ Main();return 0;}