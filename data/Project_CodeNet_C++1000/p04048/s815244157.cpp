#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define ui unsigned int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define pb push_back
#define pi 3.141592653589793
#define maxn 
#define maxm 
#define maxs 
#define M 
#define Base 
#define Hash 
#define Author Renatus
//#define DEBUG
//#define ONLINE_JUDGE
using namespace std;

ll N, X;

ll cal(ll x, ll y){
	if (x < y) swap(x, y);
	if (!y) return 0;
	if (x == y) return x;
	ll d = x / y;
	if (x % y == 0) d--;
	return d * 2 * y + cal(x - d * y, y);
}

int main(){
	
	scanf("%lld%lld", &N, &X);
	printf("%lld", cal(N - X, X) + N);
	return 0;
}