#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<list>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<limits>
#include<unordered_map>
#include<cctype>
#pragma warning(disable:4996)
using namespace std;

#define debug(i) cout<<"<debug> "<<#i<<" "<<i<<" <\\debug>"<<endl
#define mfor(i,a,b) for(int i=(a);i<=(b);i++)
#define mrep(i,a,b) for(int i=(a);i>=(b);i--)
#define lll __int128
#define Re register
#define mem(a,b) memset(a,(b),sizeof(a))
#define Design ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
typedef pair<int, int> intpair;
typedef pair<long long int, long long int> llpair;
typedef long long int ll;
const int INF = 0x3f3f3f3f;
const long long int INFLL = 0x3f3f3f3f3f3f3f3f;
#pragma comment(linker, "/STACK:1024000000,1024000000") 

const ll mod = 1e9 + 7;

long long fpow(long long a, long long n, long long mod)
{
    if (n == 0)        return 1;
    else if (n & 1) return a * fpow(a, n - 1, mod) % mod;
    else
    {
        long long num = fpow(a, n / 2, mod) % mod;
        return num * num % mod;
    }
}

long long getinv(long long a, long long mod)
{
    return fpow(a, mod - 2, mod);
}

const int maxn = 5010;
ll f[maxn][maxn];

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    f[0][0] = 1;
    mfor(i,0,n)
    {
        mfor(j, 0, i)
        {
            (f[i + 1][j + 1] += f[i][j] << 1) %= mod;
            (f[i + 1][max(j - 1, 0)] += f[i][j]) %= mod;
        }
    }
    cout << f[n][s.length()] * getinv(fpow(2, s.length(), mod), mod) % mod;
}