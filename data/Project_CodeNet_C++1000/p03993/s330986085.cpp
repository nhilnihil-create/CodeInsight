#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> l(n, -1);
    int ans = 0;
    for (int i=0; i<n; ++i) {
        int num; cin >> num;
        num--;
        ans += (l[num] == i);
        l[i] = num;
    }
    cout << ans << endl;
}