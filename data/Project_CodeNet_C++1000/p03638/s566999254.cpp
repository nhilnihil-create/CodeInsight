#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int H,W,N;
    cin >> H >> W >> N;
    int X = 1;
    int Y = 1;
    vector<vector<int>>ans(H,vector<int>(W));
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        for(int j = 0; j < a; j++) {
            if(X%2 == 1) {
                ans[X-1][Y-1] = i+1;
                if(Y+1 <= W) {
                    Y++;
                }
                else {
                    X++;
                }
            }
            else {
                ans[X-1][Y-1] = i+1;
                if(Y-1 >= 1) {
                    Y--;
                }
                else {
                    X++;
                }
            }
        }
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << ans[i][j];
            if(j+1 != W) {
                cout << " ";
            }
        }
        cout << endl;
    }
}