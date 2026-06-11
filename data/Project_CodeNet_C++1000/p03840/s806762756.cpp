#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    vector<ll> V(7);
    rep(i,0,7)cin >> V[i];
    ll ans = 0;
    int a = V[0] % 2 + V[3] % 2 + V[4] % 2;
    if(a >= 2 && min({V[0], V[3], V[4]}) >= 1){
        ans += 3;
        V[0]--,V[3]--,V[4]--;
    }
    ans += V[0] / 2 * 2;
    ans += V[1];
    ans += V[3] / 2 * 2;
    ans += V[4] / 2 * 2;
    cout << ans << endl;
}