#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long N, std::vector<long long> A){
    map<ll, ll> mp;
    for (ll i = 0; i < N; i++) mp[A[i]]++;
    vector<ll> useful;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        if(itr->second >= 2) useful.push_back(itr->first);
    }
    sort(useful.begin(), useful.end(), greater<ll>());
    ll ans = 0;
    if(useful.size() > 1){
        if(mp[useful[0]] >= 4) ans = useful[0] * useful[0];
        else ans = useful[0] * useful[1];
    }
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
