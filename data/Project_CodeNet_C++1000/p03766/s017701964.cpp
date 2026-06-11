#include <bits/stdc++.h>
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define all(x) (x).begin(), (x).end()
using namespace std;
inline ll read()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int MOD = 1e9 + 7;
int n, f[2000010], m;
int main()
{
    n = read();
    f[n] = n;
    m = n - 1;
   	for(int i = n - 1; i; i --)
    {
    	f[i] = 1LL * (n - 1) * (n - 1) % MOD;
    	(f[i] += f[i + 1]) %= MOD;
    	(f[i] += m) %= MOD;
    	m += (i + 2 > n ? 1 : f[i + 2]) - 1;
    	m %= MOD;
    }
    printf("%d\n", f[1]);
    return 0;
}
