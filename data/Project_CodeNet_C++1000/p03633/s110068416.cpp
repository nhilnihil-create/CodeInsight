#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){ return b ? gcd(b,a%b) : a; }
ll lcm(ll a, ll b){ return a/gcd(a,b)*b; }

void solve(long long N, std::vector<long long> T){
    ll ans = T[0];
    for(int i = 1; i < N; ++i){
        ans = lcm(ans, T[i]);
    }
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> T(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&T[i]);
    }
    solve(N, std::move(T));
    return 0;
}
