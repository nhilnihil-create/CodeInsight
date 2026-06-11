#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dh[4] = {0,1,0,-1};
int dw[4] = {1,0,-1,0};
int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> ans(h, vector<int>(w, 0));
    int dir = 0;
    int hh, ww = 0;
    rep(i, n) {
        rep(j, a[i]) {
            ans[hh][ww] = i + 1;
            hh += dh[dir]; ww += dw[dir];
            if(hh<0||hh>=h||ww<0||ww>=w||ans[hh][ww]!=0) {
                hh -= dh[dir]; ww -= dw[dir];
                dir = (dir+1)%4;
                hh += dh[dir]; ww += dw[dir];
            }
        }
    }
    rep(i, h) {
        rep(j, w) {
            printf("%d ",ans[i][j]);
        }puts("");
    }
}