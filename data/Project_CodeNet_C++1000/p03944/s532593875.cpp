#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main() {
    int W, H, N; cin >> W >> H >> N;
    vector<vector<int>> F(H, vector<int>(W,1));
    for (int i = 0; i < N; i++) {
        int x, y, a; cin >> x >> y >> a;
        if (a == 1) {
            for (int h = 0; h < H; h++) {
                for (int w = 0; w < x; w++) {
                    F[h][w] = 0;
                }
            }
        } else if (a == 2) {
            for (int h = 0; h < H; h++) {
                for (int w = x; w < W; w++) {
                    F[h][w] = 0;
                }
            }
        } else if (a == 3) {
            for (int h = 0; h < y; h++) {
                for (int w = 0; w < W; w++) {
                    F[h][w] = 0;
                }
            }
        } else if (a == 4) {
            for (int h = y; h < H; h++) {
                for (int w = 0; w < W; w++) {
                    F[h][w] = 0;
                }
            }
        }
    }

    int area = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (F[h][w]) area++;
        }
    }

    cout << area << endl;
    return 0;
}