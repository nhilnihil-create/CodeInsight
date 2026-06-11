#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;

int main(){
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> a(N);
    rep(i, N) {
        int input;
        cin >> input;
        input--;
        a[i] = input;
    }
    int ans[H][W] = {0};
    int now_h = 0, now_w = 0, now_col = 0;
    rep(i, H*W) {
        if (a[now_col]<0) now_col++;
        a[now_col]--;
        ans[now_h][now_w] = now_col+1;
        if (now_w==W-1 && now_h%2==0 && i!=0) {
            now_h++;
        } else if (now_w==0 && now_h%2!=0) {
            now_h++;
        } else if (now_h%2==0) {
            now_w++;
        } else {
            now_w--;
        }
    }
    rep(i, H) {
        rep(j, W) {
        cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}