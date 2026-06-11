#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    vector<vector<int>> s(w, vector<int>(h));
    rep(i,n) {
        int a, x, y;
        cin >> x >> y >> a;
        if(a==1) rep(nh,h) rep(nw,x) s[nw][nh]=1;
        if(a==2) rep(nh,h) for(int nw = x; nw < w; ++nw) s[nw][nh]=1;
        if(a==3) rep(nw,w) rep(nh,y) s[nw][nh]=1;
        if(a==4) rep(nw,w) for(int nh = y; nh < h; ++nh) s[nw][nh]=1;
        
    }
    int cnt = 0;
    rep(i,w)rep(j,h) if(s[i][j]==1) cnt++;
    cout << w*h-cnt << endl;
    return 0;
}