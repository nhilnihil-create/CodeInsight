#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <map>
#include <cctype>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <bitset>
#define rap(i, a, n) for(int i=a; i<=n; i++)
#define rep(i, a, n) for(int i=a; i<n; i++)
#define lap(i, a, n) for(int i=n; i>=a; i--)
#define lep(i, a, n) for(int i=n; i>a; i--)
#define rd(a) scanf("%d", &a)
#define rlld(a) scanf("%lld", &a)
#define rc(a) scanf("%c", &a)
#define rs(a) scanf("%s", a)
#define rb(a) scanf("%lf", &a)
#define rf(a) scanf("%f", &a)
#define pd(a) printf("%d\n", a)
#define plld(a) printf("%lld\n", a)
#define pc(a) printf("%c\n", a)
#define ps(a) printf("%s\n", a)
#define LL long long
#define ULL unsigned long long
#define Pair pair<int, int>
#define mem(a, b) memset(a, b, sizeof(a))
#define _  ios_base::sync_with_stdio(0),cin.tie(0)
//freopen("1.txt", "r", stdin);
using namespace std;
const int maxn = 1100000, INF = 0x7fffffff, MOD = 1e9 + 7;

LL D[maxn], U[maxn];
LL q_pow(LL a, LL b)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

void init()
{
    U[0] = D[0] = 1;
    for(int i = 1; i < maxn; i++)
    {
        U[i] = U[i - 1] * i % MOD;
        D[i] = q_pow(U[i], MOD - 2);
    }
}

LL C(LL n, LL m)
{
    return U[n] * D[m] % MOD * D[n - m] % MOD;
}

int main()
{
    init();

    LL h, w, a, b, ret = 0;
    cin >> h >> w >> a >> b;
    for(int i = b + 1; i <= w; i++)
    {
        ret = (ret + C(h - a + i - 2, i - 1) * C(a - 1 + w - i, a - 1)) % MOD;
     //   cout << C(h - a + i - 2, i - 1) << "    " << C(a - 1 + w - i, a - 1) << endl;
    }
   ret = (ret % MOD + MOD) % MOD;
   cout << ret << endl;




    return 0;
}