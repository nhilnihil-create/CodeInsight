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
//#pragma comment(linker, "/STACK:1024000000,1024000000") 

ll x[200010];
ll a[200010];
ll d[200010];	//差分数组
ll f[200010];
ll res[200010];
double ans[200010];

int main()
{
	Design;
	ll n, m, k;
	cin >> n;
	mfor(i, 1, n) cin >> x[i], d[i] = res[i] = i;
	cin >> m >> k;
	mfor(i, 1, m) cin >> a[i];
	mfor(i, 1, m) swap(d[a[i]], d[a[i] + 1]);
	for (ll i = k; i; i >>= 1)
	{
		//debug(i);
		if (i & 1)
		{
			mfor(i, 1, n) f[i] = res[d[i]];
			mfor(i, 1, n) res[i] = f[i];
		}
		mfor(i, 1, n) f[i] = d[d[i]];
		mfor(i, 1, n) d[i] = f[i];
	}
	mfor(i, 1, n)
	{
		ans[i] = x[res[i]] - x[res[i] - 1] + ans[i - 1];
	}
	mfor(i, 1, n) cout << fixed << setprecision(10) << ans[i] << endl;
}
