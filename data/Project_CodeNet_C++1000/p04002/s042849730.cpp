#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int h, w, n;
int dx[9] = {0, -1, -1, -1, 0, 1, 1, 1, 0};
int dy[9] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
set < pair <int, int> > st, kand;
llint cnt[10], sum;

bool ok (int x, int y) {
    return x >= 2 && x <= h - 1 && y >= 2 && y <= w - 1;
}

int f (int x, int y) {
    int res = 0;
    for (int i = 0; i < 9; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (st.find({nx, ny}) != st.end()) res++;
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
        for (int j = 0; j < 9; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (ok(nx, ny)) kand.insert({nx, ny});
        }
    }
    for (auto par : kand) {
        cnt[f(par.first, par.second)]++;
    }
    for (int i = 1; i <= 9; i++) {
        sum += cnt[i];
    }
    cnt[0] = (llint) (h - 2) * (w - 2) - sum;
    for (int i = 0; i <= 9; i++) {
        cout << cnt[i] << endl;
    }
    return 0;
}
