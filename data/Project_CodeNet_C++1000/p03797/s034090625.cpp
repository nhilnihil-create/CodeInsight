#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    ll N, M;
    cin >> N >> M;

    ll cnt = 0;

    ll a = min(N, M / 2);

    N -= a;
    M -= 2 * a;
    cnt += a;

    cnt += M / 4;

    cout << cnt << endl;
}