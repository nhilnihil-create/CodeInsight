#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int N;
vector<int> s;


void input() {
    cin >> N;
    s = vector<int>(N);
    rep(i, N) cin >> s[i];
}


int main() {
    input();
    int ans = 0;
    sort(s.begin(), s.end());
    rep(i, N) ans += s[i];
    if (ans % 10 == 0) {
        rep(i, N) {
            if (s[i] % 10 != 0) {
                ans -= s[i];
                break;
            }
        }
    }
    if (ans % 10 == 0) ans = 0;
    cout << ans << endl;
}
