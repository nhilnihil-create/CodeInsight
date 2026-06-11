#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define DUMP(x) cerr << #x << " = " << (x) << endl;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const double PI = acos(-1);



int main(void)
{
    int n;
    cin >> n;
    ll ans = 1;
    reps(i, n) ans = (ans * i) % MOD;
    cout << ans << endl;
    return 0;
}