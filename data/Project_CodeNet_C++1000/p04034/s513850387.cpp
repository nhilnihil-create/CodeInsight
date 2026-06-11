#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> cnt(N, 1);
    vector<bool> exist(N, false);
    exist[0] = true;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (exist[x]) exist[y] = true;
        cnt[x]--; cnt[y]++;
        if (cnt[x] == 0) exist[x] = false;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (exist[i]) ans++;
    }

    cout << ans << endl;
}