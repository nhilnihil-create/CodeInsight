#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int INF = 1LL << 30;
int MOD = 1e9+7;
main(){
    map<P,int> mp;
    ll H,W,N;
    cin >> H >> W >> N;
    for(int i = 0;i < N;i++){
        int x,y;
        cin >> y >> x;
        int dx[] = {-1, 0, 1,-1, 0, 1,-1, 0, 1};
        int dy[] = {-1,-1,-1, 0, 0, 0, 1, 1, 1};
        for(int j = 0;j < 9;j++){
            int nx = x + dx[j],ny = y + dy[j];
            if(nx < 1 || nx > W || ny < 1 || ny > H)continue;
            mp[P(ny,nx)]++;
        }
    }
    ll cnt[10] = {(W-2)*(H-2)};
    for(auto p:mp){
        int x = p.first.second,y = p.first.first;
        if(x == 1 || x == W || y == 1 || y == H)continue;
        cnt[p.second]++;
        cnt[0]--;
    }
    for(ll n:cnt)cout << n << endl;
}