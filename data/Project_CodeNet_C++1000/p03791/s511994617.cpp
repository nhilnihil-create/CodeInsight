#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,e) for (int i=s;i<e;i++)
#define FOE(i,s,e) for (int i=s;i<=e;i++)
#define FOD(i,s,e) for (int i=s;i>=e;i--)
#define SET(a,e) memset(a,e,sizeof(a))
#define LL long long
#define LD long double
#define pb push_back
#define x first
#define y second
#define PII pair<int,int>
#define PLI pair<LL,int>
#define PIL pair<int,LL>
#define PLL pair<LL,LL>
#define PDD pair<LD,LD>
#define eps 1e-9
#define HH1 402653189
#define HH2 1610612741

const LL MOD = 1000000007;

int n, a[100055];
LL ans, buffer, beforeu;

int main () {
	
	scanf("%d", &n);
	
	FOR(i, 0, n) scanf("%d", a + i);
	
	buffer = a[0] - 1;
	ans = 1;
	beforeu = 0;
	
	FOR(i, 1, n) {
//		printf("i = %d : buffer = %lld beforeu = %lld\n", i, buffer, beforeu);
		ans *= (i + 1 - (beforeu + 1) / 2);
		ans %= MOD;
		if (a[i] - 1 == a[i - 1]) {
			if (buffer == 0) beforeu++;
			else buffer--;
		}
		else if (a[i] - 2 > a[i - 1]) {
			buffer += a[i] - 2 - a[i - 1];
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
	
}