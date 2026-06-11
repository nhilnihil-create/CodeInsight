#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<bitset>
#include<ctime>
#include<deque>
#include<stack>
#include<functional>
#include<sstream>
//#include<cctype>
//#pragma GCC optimize(2)
using namespace std;
#define maxn 2000005
#define inf 0x7fffffff
//#define INF 1e18
#define rdint(x) scanf("%d",&x)
#define rdllt(x) scanf("%lld",&x)
#define rdult(x) scanf("%lu",&x)
#define rdlf(x) scanf("%lf",&x)
#define rdstr(x) scanf("%s",x)
typedef long long  ll;
typedef unsigned long long ull;
typedef unsigned int U;
#define ms(x) memset((x),0,sizeof(x))
const long long int mod = 1e9 + 7;
#define Mod 1000000000
#define sq(x) (x)*(x)
#define eps 1e-4
typedef pair<int, int> pii;
#define pi acos(-1.0)
//const int N = 1005;
#define REP(i,n) for(int i=0;i<(n);i++)
typedef pair<int, int> pii;
inline ll rd() {
	ll x = 0;
	char c = getchar();
	bool f = false;
	while (!isdigit(c)) {
		if (c == '-') f = true;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return f ? -x : x;
}

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}
int sqr(int x) { return x * x; }


/*ll ans;
ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1; y = 0; return a;
	}
	ans = exgcd(b, a%b, x, y);
	ll t = x; x = y; y = t - a / b * y;
	return ans;
}
*/

int n;
ll a[maxn];
ll maxleft[maxn], minrgt[maxn];
priority_queue<int, vector<int>, greater<int> >q1;
priority_queue<int>q2;


int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < 3 * n; i++)rdllt(a[i]);
	for (int i = 0; i < n; i++) {
		maxleft[0] += a[i];
		q1.push(a[i]);
		minrgt[n + 1] += a[3 * n - i - 1]; q2.push(a[3 * n - i - 1]);
	}
	for (int i = 1; i <= n; i++) {
		q1.push(a[n + i - 1]);
		maxleft[i] = maxleft[i - 1] + a[n + i - 1] - q1.top();
		q1.pop();
		q2.push(a[2 * n - i]);
		minrgt[n - i + 1] = minrgt[n - i + 1 + 1] + a[2 * n - i] - q2.top();
		q2.pop();
	}
	ll maxx = -inf * 1ll;
	for (int i = 0; i <= n; i++) {
		if (i == 0)maxx = maxleft[i] - minrgt[i + 1];
		else maxx = max(maxx, maxleft[i] - minrgt[i + 1]);
	}
	cout << maxx << endl;
	return 0;
}