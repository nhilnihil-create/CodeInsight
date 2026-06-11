#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    vector<int> b(100002, 0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        b[a]++, b[a+1]++, b[a+2]++;
    }
    int ans = 0;
    for (int i = 0; i < 100002; i++)
        ans = max(ans, b[i]);
    cout << ans << endl;
}