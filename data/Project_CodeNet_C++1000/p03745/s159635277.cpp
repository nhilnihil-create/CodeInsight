#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = 1;
    int direction = 0;
    for (int i = 1; i < n; i++) {
        if (direction == 0) {
            if (a[i-1] == a[i]) continue;
            else if (a[i-1] < a[i]) direction = 1;
            else direction = -1;
        }
        else if (direction == 1) {
            if (a[i-1] <= a[i]) continue;
            ans++;
            direction = 0;
        }
        else { // direction == -1
            if (a[i-1] >= a[i]) continue;
            ans++;
            direction = 0;
        }
    }
    cout << ans << endl;
}