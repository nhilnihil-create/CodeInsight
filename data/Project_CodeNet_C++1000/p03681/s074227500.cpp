#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
static const ll MOD = 1e9+7;

int main(){
    ll N,M;
    cin>>N>>M;

    ll dif = abs(N-M);
    ll ans;

    if(dif >= 2){
        ans = 0;
    }

    else if(dif == 0){
        ans = 1;
        ans *= 2;

        for(int i=2; i<=M; i++){
            ans *= i;
            ans %= MOD;
        }

        for(int i=2; i<=N; i++){
            ans *= i;
            ans %= MOD;
        }
    }

    else if(dif == 1){
        ans = 1;
        for(int i=2; i<=M; i++){
            ans *= i;
            ans %= MOD;
        }

        for(int i=2; i<=N; i++){
            ans *= i;
            ans %= MOD;
        }
    }

    cout<<ans<<endl;
}