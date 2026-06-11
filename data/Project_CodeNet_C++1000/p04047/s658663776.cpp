#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int ans;
int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) ans += v[i*2];
    cout << ans << endl;
    return 0;
}