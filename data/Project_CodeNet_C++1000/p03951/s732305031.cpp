#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int ans = 2 * n;
    for (int i = n - 1; i >= 0; i--) {
        if (s.substr(i, n - i) == t.substr(0, n - i)) {
            int tmp = (s.substr(0, i) + t).size();
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
}
