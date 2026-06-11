#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define all(v) v.begin(), v.end()
#define repi(i, n, init) for (ll i = init; i < (n); i++)
#define repd(i, n, init) for (ll i = (n); i >= init; i--)
#define repm(i, m) for (auto i = m.begin(); i != m.end(); i++)

int main()
{
    string A, B, C;
    cin >> A >> B >> C;
    cout << (A.at(A.length() - 1) == B.at(0) && B.at(B.length() - 1) == C.at(0) ? "YES" : "NO") << endl;
    return 0;
}