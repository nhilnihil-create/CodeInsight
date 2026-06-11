#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> Box(N, 1);
    vector<bool> Red(N, false);
    Red[0] = true;
    while (M--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        Red[y] = Red[y] || Red[x];
        if (Box[x] <= 1) Red[x] = false;
        --Box[x];
        ++Box[y];
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (Red[i]) ++res;
    }
    cout << res << endl;
    return 0;
}