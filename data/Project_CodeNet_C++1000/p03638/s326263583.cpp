#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> ans(h, vector<int>(w));
    int cnt = 0;
    rep(i, n)rep(j, a[i]){
        int y = cnt / w;
        int x = 0;
        if(y % 2 == 0) x = cnt % w;
        else x = w - cnt % w - 1;
        ans[y][x] = i + 1;
        cnt++;
    }
    rep(i, h){
        rep(j, w) cout << ans[i][j] << " ";
        cout << endl;
    }
}