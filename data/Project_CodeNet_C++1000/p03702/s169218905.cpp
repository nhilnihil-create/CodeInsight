#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
ll INF = (1LL << 30) - 1;
int MOD = 1e9+7;
ll N,A,B;
vector<ll> V;
bool judge(ll x){
    ll cnt = 0;
    rep(i,0,N){
        if(V[i] <= B * x)continue;
        cnt += (V[i] - B * x + A - B - 1) / (A-B);
    }
    return cnt <= x;
}
main(){
    cin >> N >> A >> B;
    V.resize(N);
    rep(i,0,N)cin >> V[i];
    ll ok = INF, ng = -1;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(judge(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
}