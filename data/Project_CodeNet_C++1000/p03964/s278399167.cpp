#include <bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
signed main()
{
    int N;
    cin >> N;
    int nt = 1, na = 1;
    int n;
    rep(i, N)
    {
        int T, A;
        cin >> T >> A;
        n = max((nt + T - 1) / T, (na + A - 1) / A);
        nt = n * T;
        na = n * A;
    }
    cout << na + nt << endl;
}
