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
    map<P,int> mp;
    rep(i,0,N){
        int a,b;
        cin >> a >> b;
        a--,b--;
        int dx[] = {-1,-1,-1,0,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,0,1,-1,0,1};
        rep(j,0,9){
            int ny = a + dy[j];
            int nx = b + dx[j];
            if(ny < 1 || ny >= H-1 || nx < 1 || nx >= W-1)continue;
            mp[P(ny, nx)]++;
        }
    }
    ll cnt[10] = {}, sum = 0;
    for(auto p:mp){
        //cout << p.first.first << " " << p.first.second << endl;
        cnt[p.second]++;
    }
    rep(i,0,10)sum += cnt[i];
    cnt[0] = (H-2) * (W-2) - sum;
    rep(i,0,10){
        cout << cnt[i] << endl;
    }
}