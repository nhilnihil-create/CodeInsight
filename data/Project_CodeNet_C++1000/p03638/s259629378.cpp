#include <bits/stdc++.h>
using namespace std;

//#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))

int H, W, N;
vector<vector<int>> ans(100,vector<int>(100,-1));

bool is_safe(int x, int y){
    if((0 <= x && x < W)&&(0 <= y && y < H)){
        return ans[y][x] == -1;
    }
    return false;
}

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

signed main(){
    cin >> H >> W >> N;

    queue<int> brush;
    reps(i,1,N){
        int a; cin >> a;
        rep(j,a) brush.push(i);
    }
    
    int x = 0, y = 0, dir = 0;
    rep(i, H*W){
        ans[y][x] = brush.front();
        brush.pop();
        if(!is_safe(x+dx[dir], y+dy[dir])){
            dir = (dir + 1) % 4;
        }
        x += dx[dir];
        y += dy[dir];
    }
    
    rep(i,H){
        rep(j,W) cout << (j ? " " : "") << ans[i][j];
        cout << endl;
    }
}