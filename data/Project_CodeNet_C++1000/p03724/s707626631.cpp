#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int c[100010]; // c[i] : i, i+1を結ぶ道のコスト

int main(){
    int n, m;
    cin >> n >> m;

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        c[min(a,b)]++;
        c[max(a,b)]--;
    }
    rep(i, n) c[i+1] += c[i];

    bool flag = true;
    rep(i, n+1) flag &= (c[i]%2 == 0);

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
