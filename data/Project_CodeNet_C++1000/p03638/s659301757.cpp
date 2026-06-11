#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

// 069d
int main(){
    int h, w, n;
    cin >> h >> w >> n;
    int a[n];
    rep(i, n) cin >> a[i];

    // 一筆書き
    vector<vector<int>> s(h, vector<int>(w));
    int hh = 0, ww = 0;
    rep(i, n)rep(j, a[i]){
        s[hh][ww] = i+1;
        ww++;
        if(ww == w){
            ww = 0;
            hh++;
        }
    }

    rep(i, h){
        if (i%2==0){
            rep(j, w) cout << s[i][j] << ' ';
        }else{
            for(int j=w-1; j>=0; j--) cout << s[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
