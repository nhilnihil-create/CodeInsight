#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int H, W; cin >> H >> W;
    int N; cin >> N;
    vector<int> a(N+1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    int tmp = 1;
    vector< vector<int> > ans(H, vector<int>(W));
    pair<int, int> now = make_pair(0, 0);
    bool flag = true;
    while (tmp <= N) {
        while (a[tmp] > 0) {
            a[tmp]--;
            ans[now.first][now.second] = tmp;
            if (flag && now.second < W-1) now.second++;
            else if (flag && now.second >= W-1) {
                now.first++;
                flag = false;
            }
            else if (!flag && now.second > 0) now.second--;
            else if (!flag && now.second <= 0) {
                now.first++;
                flag = true;
            }
        }
        tmp++;
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
}
