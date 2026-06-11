#include <bits/stdc++.h>
using namespace std;
 
using pii = pair<int, int>;
using ll = long long;
 
constexpr int INF = 1e9;
 
int main() {
    int H, W, D;
    cin >> H >> W >> D;
    string color = "RYGB";
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            int mask = 0;
            // rotate 45
            mask |= (i + j) / D % 2;
            mask |= ((H - 1 - (i - j)) / D % 2) << 1;

            cout << color[mask];
        }
        cout << endl;
    }
}
