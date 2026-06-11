#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int> > vt(N);
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        vt.emplace_back(make_pair(a, b));
    }
    sort(vt.begin(), vt.end(), greater<>());

    cout << vt[0].first + vt[0].second << endl;
    return 0;
}