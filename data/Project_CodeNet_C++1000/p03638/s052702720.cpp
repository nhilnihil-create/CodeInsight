#include <bits/stdc++.h>

#define mod 1000000007
#define REP(i, n) for (int i = 0; i < n; i++)

using namespace std;

/*long C(long n, long r){
    if(n < r) return 0;
    long p[n+1][n+1];
    p[0][0] = 1;
    for(int i = 1; i <= n; i++){
        p[i][0] = 1;
        p[i][i] = 1;
        for(int j = 1; j <= i-1; j++){
            p[i][j] = p[i-1][j] + p[i-1][j-1];
        }
    }
    return p[n][r];
}*/

 
void solve() {
    int H, W, N;
    cin >> H >> W >> N;
    int a[N];
    REP(i, N) cin >> a[i];
    int ans[H][W];
    int k = 0;
    REP(i, N){
        REP(j, a[i]){
            int h = k / W;
            int w = k % W;
            if(h % 2 == 0){
                ans[h][w] = i+1;
            }
            else{
                ans[h][W-1-w] = i+1;
            }
            k++;
        }
    }
    REP(i, H){
        REP(j, W) cout << ans[i][j] << " ";
        cout << "\n";
    }
}
 
int main() {
    solve();
    return 0;
}