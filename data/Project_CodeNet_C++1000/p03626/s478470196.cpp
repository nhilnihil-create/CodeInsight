#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

const int mod = 1000000007;
int add(int a, int b) { return (a += b) < mod? a : a - mod; }
int sub(int a, int b) { return (a -= b) >=  0? a : a + mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
void adds(int& a, int b) { a = add(a, b); }
void subs(int& a, int b) { a = sub(a, b); }
void muls(int& a, int b) { a = mul(a, b); }
void maxs(int& a, int b) { a = max(a, b); }
void mins(int& a, int b) { a = min(a, b); }
int pwr(int a, ll p) {
    if (p == 0) return 1;
    if (p & 1) return mul(a, pwr(a, p - 1));
    return pwr(mul(a, a), p / 2);
}
int inv(int a) { return pwr(a, mod - 2); }

int n;
string s[2];
int dp[52][4][4];

int f(int k, int a, int b)
{
    if (k == n) return 1;
    if (dp[k][a][b] != -1) return dp[k][a][b];
    int sol = 0;
    if (s[0][k] == s[1][k])
    {
        for (int i = 0; i < 3; ++i)
            if (i != a && i != b)
                adds(sol, f(k + 1, i, i));
    }
    else
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (i != j && i != a && j != b)
                    adds(sol, f(k + 2, i, j));
    }
    return dp[k][a][b] = sol;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s[0] >> s[1];
    memset(dp, -1, sizeof dp);
    cout << f(0, 3, 3);
}
