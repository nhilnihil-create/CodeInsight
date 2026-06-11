#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int H, W; cin >> H >> W;
    vector<string> ans(H + 2);
    for(int h = 0; h < H + 2; h++) {
        if(h == 0 || h == H + 1) {
            for(int w = 0; w < W + 2; w++) ans[h].push_back('#');
        }
        else {
            ans[h].push_back('#');
            for(int w = 1; w < W + 1; w++) {
                char s; cin >> s;
                ans[h].push_back(s);
            }
            ans[h].push_back('#');
        }
    }
    for(int h = 0; h < H + 2; h++) {
        for(int w = 0; w < W + 2; w++) {
            if(w != W + 1) cout << ans[h][w];
            else cout << ans[h][w] << endl;
        }
    }
    return 0;
}