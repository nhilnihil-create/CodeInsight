#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans;
    cin >> n;
    vector<int> si(n);
    vector<int> sj;
    for (int i = 0; i < n; i++) {
        cin >> si.at(i);
        if (si.at(i) % 10 != 0) sj.push_back(si.at(i));
    }
    sort(sj.begin(), sj.end());
    ans = accumulate(si.begin(), si.end(), 0);
    if (ans % 10 == 0) {
        if (sj.size() >= 1) ans -= sj.at(0);
        else ans = 0;
    }
    cout << ans << endl;
    return 0;
}