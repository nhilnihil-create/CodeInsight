#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define rep1(i, n) for (int i = 1; i < int(n); ++i)
#define repx(i, x, n) for (int i = int(x); i < int(n); ++i)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define ALL(n) begin(n), end(n)
#define IN(a, x, b) ((a) <= (x) && (x) < (b))
#define OUT(a, x, b) ((x) < (a) || (x) < (b))
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;
const ll MOD = 1000000007;

int main()
{
    int N, a, b;
    ll A, B, n;
    A = 1;
    B = 1;
    cin >> N;
    rep(i, N)
    {
        cin >> a >> b;
        n = max(ll((A + a - 1) / a), ll((B + b - 1) / b));
        A = n * a;
        B = n * b;
    }
    cout << A + B << endl;
    return 0;
}
