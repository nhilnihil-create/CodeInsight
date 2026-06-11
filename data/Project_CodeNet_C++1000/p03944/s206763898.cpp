#include <bits/stdc++.h>
#define INF 1e9
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define FORE(i, a, b) for (int i = (a), e = (b); i < e; ++i)
#define RFORE(i, a, b) for (int i = (b)-1, e = (a); i >= e; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(c) sort((c).begin(), (c).end())
#define SORTR(c) sort((c).begin(), (c).end(), greater<int>())
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int W, H, N;
    cin >> W >> H >> N;
    int X = 0;
    int Y = 0;
    for (int i = 0; i < N; i++) {
        int x, y, a;
        cin >> x >> y >> a;
        switch (a) {
            case 1: X = X < x ? x : X; break;
            case 2: W = x < W ? x : W; break;
            case 3: Y = Y < y ? y : Y; break;
            case 4: H = y < H ? y : H; break;
        }
    }
    cout << max(W - X, 0) * max(H - Y, 0) << endl;
}
