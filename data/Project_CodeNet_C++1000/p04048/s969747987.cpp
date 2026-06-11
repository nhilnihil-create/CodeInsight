#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;

const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1000000000000000000L;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int ddx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};

ll ans = 0;

void calc(ll a, ll b) {
    if(b == 0) return;
    ans += a / b * b * 3;
    calc(b, a % b);
}

int main() {
    ll N, X;
    cin >> N >> X;

    calc(N - X, X);

    cout << ans << endl;
}
