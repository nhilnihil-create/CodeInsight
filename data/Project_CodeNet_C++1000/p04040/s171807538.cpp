#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;

#define pb push_back
#define All(a) a.begin(), a.end()
#define met(a, b) memset(a, b, sizeof(a))
#define rep1(i, l, r) for(int i = l; i <= r; ++i)
#define rep2(i, l, r) for(int i = l; i < r; ++i) 
#define per(i, r, l) for(int i = r; i >= l; --i)
typedef long long ll;
typedef double db;
typedef long double ldb;
const int NIL = -1;
const int oo = 0x3f3f3f3f;
const ll INF = 2e18;
const db eps = 1e-8;
const db PI = acos(-1.0);
const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;

struct node
{
	int x, y;
	node(int a, int b):x(a), y(b){}
};

ll C1[maxn], C2[maxn];

inline int read(void)
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9')	{ if(ch == '-') f = -1; ch = getchar(); } 
	while(ch >= '0' && ch <= '9') {	x = (x << 1) + (x << 3) + ch - '0';	ch = getchar();	}
	return x * f;
}

inline void write(ll x)
{
	if(x < 0) { putchar('-'); x = -x; }
    if(x>=10) write(x/10); 
	putchar(x%10+'0'); 
}

ll find(ll a, ll b)
{
	if(a == 1) return 1;
	ll ans = b / a + 1;
	ans = ans * find(a*ans-b, b) % b;
	return ans;
}

int main(void)
{
	int n = read(), m = read(), a = read(), b = read();
	node begin(1, 1), mid(n-a, b+1), end(n, m);
	C1[0] = C2[0] = 1;
	int n1 = n-a-1+b, n2 = a+m-b-1;
	C1[n1] = C2[n2] = 1;
	rep1(i, 1, n1/2) C1[n1-i] = C1[i] = C1[i-1] * (n1 - i + 1) % mod * find(i, mod) % mod;
	rep1(i, 1, n2/2) C2[n2-i] = C2[i] = C2[i-1] * (n2 - i + 1) % mod * find(i, mod) % mod;
//	if((n1&1)== 0) cout<<C1[n1/2-1]<<" "<<C1[n1/2]<<" "<<C1[n1/2+1]<<endl;
//	else cout<<C1[n1/2]<<" "<<C1[n1/2+1]<<endl;
//	if((n2&1) == 0) cout<<C2[n2/2-1]<<" "<<C2[n2/2]<<" "<<C2[n2/2+1]<<endl;
//	else cout<<C2[n2/2]<<" "<<C2[n2/2+1]<<endl;
	ll ans = 0;
	while(mid.x > 0 && mid.y <= m)
	{
		ans = (ans + C1[mid.y-1] * C2[end.y-mid.y] % mod) % mod;
		--mid.x;
		++mid.y;
	}
	cout<<ans;
	
	return 0;
} 