#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1000000000;

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    vector<vector<bool>>is_filled(H, vector<bool>(W));

    for (int i=0; i<N; i++){
        int xi, yi, ai;
        cin >> xi >> yi >> ai;
        if (ai == 1){
            for (int x=0; x<xi; x++){
                for (int y=0; y<H; y++){
                    is_filled[y][x] = true;
                }
            }
        }
        else if (ai == 2){
            for (int x=xi; x<W; x++){
                for (int y=0; y<H; y++)is_filled[y][x] = true;
            }
        }
        else if (ai == 3){
            for (int x=0; x<W; x++){
                for (int y=0; y<yi; y++)is_filled[y][x] = true;
            }
        }
        else {
            for (int x=0; x<W; x++){
                for (int y=yi; y<H; y++)is_filled[y][x] = true;
            }
        }
    }
    int ans = 0;
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            if (!is_filled[i][j])ans++;
        }
    }
    cout << ans << endl;
}