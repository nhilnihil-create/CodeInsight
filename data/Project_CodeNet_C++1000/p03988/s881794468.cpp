#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    map<int,int> cnt;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        cnt[a]++;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (int i = v[0]; i >= (v[0] + 3) / 2; i--) {
        if (cnt[i] < 2) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    for (int i = (v[0] - 1) / 2; i >= 1; i--) {
        if (cnt[i] != 0) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    if (v[0] & 1) {
        if (cnt[(v[0] + 1) / 2] != 2) {
            cout << "Impossible" << endl;
            return 0;
        }
    } else {
        if (cnt[(v[0] + 1) / 2] != 1) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}
