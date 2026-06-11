#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int idx = -1;
    for (int i = 0; i < N - 1; i++) {
        if (a[i] + a[i + 1] >= L) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "Impossible" << endl;
        return 0;
    }

    vector<int> ans;
    for (int i = 0; i < idx; i++) {
        ans.push_back(i);
    }
    for (int i = N - 2; i >= idx + 1; i--) {
        ans.push_back(i);
    }
    ans.push_back(idx);

    cout << "Possible" << endl;
    for (int as : ans) {
        cout << as + 1 << endl;
    }
}
