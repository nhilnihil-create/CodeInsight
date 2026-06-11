#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll,ll>> prime_factrize(ll N){
    vector<pair<ll,ll>> res;
    for(int a = 2; a * a <= N; a++){
        ll ex = 0;
        while(N % a == 0){
            ex++;
            N /= a;
        }
        res.push_back({a,ex});
    }
    if(N != 1) res.push_back({N,1});
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<ll> ex(n + 1, 0);
    for(int N = 2; N <= n; N++){
        const auto &res = prime_factrize(N);
        for(auto p : res) ex[p.first] += p.second;
    }
    ll res = 1;
    for(int p = 2; p <= n; p++){
        res *= ex[p] + 1;
        res %= (ll)(1e9 + 7);
    }
    cout << res << endl;
}