#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> n(3);
    cin >> n[0] >> n[1] >> n[2];
    sort(n.begin(), n.end());
    bool exist_e = false;
    for (int i=0; i<3; ++i) {
        if (n[i]%2 == 0) exist_e = true;
    }
    long long ans = 0;
    if (!exist_e) ans = n[1] * n[0];
    cout << ans << endl;
}