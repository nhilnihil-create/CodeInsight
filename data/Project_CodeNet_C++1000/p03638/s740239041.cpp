#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int H, W;
vector<vector<int>> G;

int cnt = 0;
void painting(int x, int y, int tar, vector<int> &A, bool &judge) {
    G[y][x] = tar + 1;
    cnt++;
    A[tar]--;
    if (A[tar] == 0)
        tar++;
    if (cnt == H * W)
        return;
    int nx, ny;
    if (judge && y == H - 1) {
        judge = 0;
        ny = H - 1;
        nx = x + 1;
    } else if (!judge && y == 0) {
        judge = 1;
        ny = 0;
        nx = x + 1;
    } else if (judge) {
        nx = x;
        ny = y + 1;
    } else {
        nx = x;
        ny = y - 1;
    }
    painting(nx, ny, tar, A, judge);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W;
    int N;
    cin >> N;
    G.assign(H, vector<int>(W));
    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }

    bool judge = 1;
    painting(0, 0, 0, A, judge);

    rep(i, H) {
        rep(j, W) { cout << G[i][j] << " "; }
        cout << endl;
    }
}