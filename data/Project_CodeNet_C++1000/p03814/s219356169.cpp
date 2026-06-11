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
    string s;
    cin >> s;
    int ans_a = 0, ans_z = 0;
    rep(i, s.size())
    {
        if (s[i] == 'A')
        {
            ans_a = i;
            break;
        }
    }
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] == 'Z')
        {
            ans_z = i;
            break;
        }
    }
    cout << ans_z - ans_a + 1 << endl;
    return 0;
}
