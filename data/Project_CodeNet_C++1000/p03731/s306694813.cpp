#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int N, T;
vector<int> t;


void input() {
    cin >> N >> T;
    t = vector<int>(N);
    rep(i, N) cin >> t[i];
}


int main() {
    input();
    ll ans = 0;
    rep(i, N - 1) {
        int x = min(T, t[i + 1] - t[i]);
        ans += x;
    }
    ans += T;
    cout << ans << endl;
}
