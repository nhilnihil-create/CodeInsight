#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    ll N,M;
    cin>>N>>M;

    ll ans = N==M ? 2 : 1;
    while(true){
        ans *= (N*M)%1000000007;
        ans %= 1000000007;
        N--;
        M--;
        if(min(N, M) == 0){
            if(max(N, M) > 1) ans = 0;
            break;
        }
    }

    cout << ans << endl;
}
