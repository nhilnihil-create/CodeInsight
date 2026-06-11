#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MOD = 1000000007;

void solve(long long N, std::vector<long long> A){
    map<ll, ll> idealmp;
    for(ll i = 1; i < N; i++){
        ll cnt = abs((N-i) - (i-1));
        idealmp[cnt]++;
    }
    map<ll, ll> mp;
    for(auto a : A) mp[a]++;
    ll pos = 0;
    if(N % 2 == 0) pos = 1;
    ll ans = 1;
    for(ll i = pos; i <= N-1; i += 2){
        if(i == 0 && (mp[i] != 1)){
            ans = 0;
            break;
        }
        if((i > 0 && i < N-1) && mp[i] != 2){
            ans = 0;
            break;
        }
        ans *= (mp[i] % MOD);
        ans %= MOD;
    }
    cout << ans << endl;
    /*
    cout << "-- real --" << endl;
    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        cout << itr->first << " " << itr->second << endl;
    }
    cout << "-- ideal --" << endl;
    for(auto itr = idealmp.begin(); itr != idealmp.end(); itr++){
        cout << itr->first << " " << itr->second << endl;
    }
    */
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
