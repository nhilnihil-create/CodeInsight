#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> cnt(N, 1);
    vector<bool> has_red(N);
    has_red[0] = true;

    REP(_, M) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        --cnt[x];
        ++cnt[y];
        if (has_red[x]) {
            has_red[y] = true;
            if (cnt[x] == 0) {
                has_red[x] = false;
            }
        }
    }

    cout << accumulate(all(has_red), 0) << endl;

    return 0;
}
