#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t.at(i);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (i < N - 1) {
            ans += min(T, t.at(i + 1) - t.at(i));
        } else {
            ans += T;
        }
    }
    cout << ans << endl;
}