#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <functional>
#include <random>
#define REP(i,a,n) for(int i=a;i<=n;++i)
#define PER(i,a,n) for(int i=n;i>=a;--i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(a) ({REP(__i,1,n) cout<<a[__i]<<' ';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head



const int N = 1e6+50;
char s[N], ans[N];
int n, f[N], nxt[N][26];

int main() {
	scanf("%s",s+1);
	n = strlen(s+1);
	REP(i,0,25) nxt[n+1][i]=nxt[n+2][i]=n+1;
	int sta = 0, mx = (1<<26)-1;
	f[n+1] = 1;
	PER(i,1,n) {
		sta |= 1<<s[i]-'a';
		f[i] = f[i+1];
		if (sta==mx) ++f[i], sta = 0;
		memcpy(nxt[i],nxt[i+1],sizeof nxt[0]);
		nxt[i][s[i]-'a']=i;
	}
	f[n+1] = 0;
	int len = f[1], now = 1;
	REP(i,1,len) {
		REP(j,'a','z') {
			int t = nxt[now][j-'a']+1;
			if (i+f[t]<=len) {
				now = t, ans[i] = j;
				break;
			}
		}
	}
	puts(ans+1);
}






