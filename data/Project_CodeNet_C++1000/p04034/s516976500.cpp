#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, bool>> data(N, make_pair(1, false));
    data.at(0).second = true;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        if (data.at(x - 1).second) {
            data.at(y - 1).second = true;
        }
        data.at(x - 1).first--;
        data.at(y - 1).first++;
        if (data.at(x - 1).first == 0) {
            data.at(x - 1).second = false;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (data.at(i).second) {
            ans++;
        }
    }

    cout << ans << endl;
}