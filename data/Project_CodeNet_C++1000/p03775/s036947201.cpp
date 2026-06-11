#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll N;
    cin >> N;
    ll ans = 1000000000000;
    for(ll i=1;i*i<=N;i++){
        if(N%i!=0) continue;
        ll A = i;
        ll B = N/i;
        ll cntA=0;
        ll cntB=0;
        while(A!=0){
            A/=10;
            cntA++;
        }
        while(B!=0){
            B/=10;
            cntB++;
        }
        ans = min(ans,max(cntA,cntB));
    }
    cout << ans << endl;
    return 0;
}