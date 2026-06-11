#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> P;

int H, W, N;
P ab[100000];
map<P, bool> mp, use;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W >> N;
    for(int i = 0; i < N; ++i) {
        cin >> ab[i].first >> ab[i].second;
        mp[ab[i]] = true;
    }
    int count[10] = { 0 };
    int dx[] = {1, -1, 0, 0, 1, -1, 1, -1, 0}, dy[] = {0, 0, 1, -1, 1, -1, -1, 1, 0};
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < 9; ++j) {
            int nx = ab[i].second + dx[j], ny = ab[i].first + dy[j];
            if(nx < 2 || nx > W - 1 || ny < 2 || ny > H - 1) continue;
            if(use[P(ny, nx)]) continue;
            use[P(ny, nx)] = true;
            int cnt = 0;
            for(int k = 0; k < 9; ++k) {
                int sx = nx + dx[k], sy = ny + dy[k];
                if(mp[P(sy, sx)]) ++cnt;
            }
            ++count[cnt];
        }
    }
    int sum = 0;
    for(int i = 1; i < 10; ++i) sum += count[i];
    count[0] = (H - 2) * (W - 2) - sum;
    for(int i = 0; i < 10; ++i) cout << count[i] << endl;
    return 0;
}