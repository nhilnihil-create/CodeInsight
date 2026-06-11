#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int H, W; cin >> H >> W;
    int N; cin >> N;
    vector<int> a(N);
    rep(i, N){
        cin >> a[i];
    }

    int c[H][W];
    int acnt = 0;
    int now = 0;
    for (int i = 0; i < H; i++){
        if(i%2 == 0){
            for (int j = 0; j < W; j++){
                if(now == 0){
                    now = a[acnt];
                    acnt++;
                }
                c[i][j] = acnt;
                now--;
            }
        } else {
            for (int j = W-1; j >= 0; j--){
                if(now == 0){
                    now = a[acnt];
                    acnt++;
                }
                c[i][j] = acnt;
                now--;
            }
        }
    }

    rep(i, H){
        rep(j, W){
            cout << c[i][j];
            if(j == W-1){
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }

    return 0;
}