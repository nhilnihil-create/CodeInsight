#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int W, H, N;
    cin >> W >> H >> N;

    vector<vector<bool> > c(H, vector<bool>(W));

    for(int i = 0; i < N; i++) {
        int x, y, a;
        cin >> x >> y >> a;
        
        if(a == 1) {
            for(int j = 0; j < H; j++) {
                for(int k = 0; k < x; k++) {
                    c[j][k] = true;
                }
            }
        } else if(a == 2) {
            for(int j = 0; j < H; j++) {
                for(int k = x; k < W; k++) {
                    c[j][k] = true;
                }
            }
        } else if(a == 3) {
            for(int j = 0; j < y; j++) {
                for(int k = 0; k < W; k++) {
                    c[j][k] = true;
                }
            }
        } else {
            for(int j = y; j < H; j++) {
                for(int k = 0; k < W; k++) {
                    c[j][k] = true;
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(c[i][j]) continue;
            ans++;
        }
    }

    cout << ans << endl;
}