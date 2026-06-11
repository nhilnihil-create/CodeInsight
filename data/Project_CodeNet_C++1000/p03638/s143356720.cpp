// AtCoder template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long ll;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // 入出力
    int h,w,n; cin >> h >> w >> n;
    int a[n]; rep(i,n) cin >> a[i];
    int c[h][w];

    // グリッド一筆書きを作る
    vector<pair<int,int>> road;
    rep(i,h){
        if(i%2) rep(j,w) road.emplace_back(i,w-j-1);
        else rep(j,w) road.emplace_back(i,j);
    }

    // 辿る
    int nc = 0;
    rep(i,h*w){
        int y = road[i].first, x = road[i].second;
        if(a[nc] == 0) nc++;
        c[y][x] = nc+1;
        a[nc]--;
    }

    // 出力
    rep(i,h){
        rep(j,w) cout << c[i][j] << " ";
        cout << "\n";
    }
}