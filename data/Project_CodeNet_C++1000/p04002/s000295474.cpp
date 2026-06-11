#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    ll H,W,N;
    cin >> H >> W >> N;
    map<P, int> mp;
    rep(i,0,N){
        int y,x;
        cin >> y >> x;
        y--,x--;
        rep(j,-1,2)rep(k,-1,2){
            if(y + j < 1 || y + j >= H-1 || x + k < 1 || x + k >= W-1)continue;
            mp[P(y + j, x + k)]++;
        }
    }
    ll cnt[10] = {(H-2) * (W-2)};
    ll sum = 0;
    for(auto pp:mp){
        cnt[pp.second]++;
    }
    rep(i,1,10)sum += cnt[i];
    cnt[0] -= sum;
    rep(i,0,10)cout << cnt[i] << endl;
}