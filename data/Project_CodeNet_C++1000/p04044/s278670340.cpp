#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 105;
int n, m;
string s[N];
string ans;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    sort(s, s + n);
    for (int i = 0; i < n; ++i) {
        ans += s[i];
    }
    cout << ans << endl;
    return 0;
}
