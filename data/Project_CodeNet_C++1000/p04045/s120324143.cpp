#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool check(ll N, vector<ll>&D){
    while(N>=0){
        ll x = N%10;
        for(auto elm : D){
            if(x == elm)
                return false;
        }
        if(N<10) N = -1;
        else N /= 10;

    }
    return true;
}

void solve(long long N, long long K, std::vector<long long> D){

    for (ll i = N; i < 100001; i++)
    {
        if(check(i,D)){
            cout << i << endl;
            return;
        }
    }
    
}

signed main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> D(K);
    for(int i = 0 ; i < K ; i++){
        scanf("%lld",&D[i]);
    }
    solve(N, K, std::move(D));
    return 0;
}
