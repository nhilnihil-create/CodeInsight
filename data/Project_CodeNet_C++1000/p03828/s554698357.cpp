#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

vector<pair<ll,ll>> count_num(ll N){
    vector<pair<ll,ll>> num_pair;
    for(ll i = 2; i * i <= N; ++i){
        if (N % i != 0) continue;
        ll cnt = 0;
        while (N % i == 0)
        {
            ++cnt;
            N /= i;
        }
        num_pair.push_back({i,cnt});          
    } 
    if(N!=1){
        num_pair.push_back({N,1});
    }
    return num_pair;
}

int main() {
    ll N;
    cin >> N;
    ll ans = 1;
    vector<long long> exp(N+1, 0);

    for(ll n = 2; n <= N; ++n){
        const auto &num_pair = count_num(n);
        for(auto p:num_pair) exp[p.first] += p.second;
    }

    for(ll i = 2; i <= N; ++i){
        ans *= (exp[i] + 1);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}