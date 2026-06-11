#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) std::cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) std::cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) std::cout << x << endl;
#define println(x) std::cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    unordered_map<int, int> cnt;
    rep(i, n) cnt[A[i]] = 0; 
    rep(i, n) cnt[A[i]]++;

    ll remove = 0;
    for (auto& kv: cnt) {
        remove += kv.second - 1;
    }

    ll nOp = (remove + 1) / 2;
    ll res = n - nOp * 2;

    put(res);
}
signed main(){ Main();return 0;}