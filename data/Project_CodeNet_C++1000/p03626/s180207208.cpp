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



#ifdef ONLINE_JUDGE
const int N = 1e6+50;
#else
const int N = 1e2+10;
#endif


int n;
char s1[N],s2[N];
int dp[N][3][3][3][3];
void add(int &a, int b) {a+=b;if (a>=P) a-=P;}
int main() {
	scanf("%d%s%s",&n,s1+1,s2+1);
	if (n==1) return puts("3"),0;
	if (n==2) return puts("6"),0;
	if (s1[1]==s2[1]) {
		if (s1[2]==s2[2]) { 
			REP(z1,0,2) REP(z2,0,2) if (z1!=z2) { 
				++dp[2][z1][z2][z1][z2];
			}
		}
		else { 
			REP(z,0,2) REP(u2,0,2) REP(d2,0,2) if (z!=u2&&z!=d2&&u2!=d2) {
				++dp[2][z][u2][z][d2];
			}
		}
	}
	else {
		REP(z1,0,2) REP(z2,0,2) if (z1!=z2) ++dp[2][z1][z1][z2][z2];
	}
	int ans = 0;
	REP(i,3,n+1) {
		REP(u1,0,2) REP(u2,0,2) {
			REP(d1,0,2) REP(d2,0,2) {
				int &r = dp[i-1][u1][u2][d1][d2];
				if (!r) continue;
				if (i==n+1) add(ans,r);
				if (s1[i]==s2[i]) {
					REP(z,0,2) if (z!=u2&&z!=d2) add(dp[i][u2][z][d2][z],r);
				}
				else if (s1[i]==s1[i-1]) {
					if (s2[i]==s2[i-1]) {
						add(dp[i][u2][u2][d2][d2],r);
					}
					else {
						REP(z,0,2) if (z!=u2&&z!=d2) add(dp[i][u2][u2][d2][z],r);
					}
				}
				else {
					if (s2[i]==s2[i-1]) {
						REP(z,0,2) if (z!=u2&&z!=d2) add(dp[i][u2][z][d2][d2],r);
					}
					else {
						REP(z1,0,2) REP(z2,0,2) if (z1!=u2&&z1!=z2&&z2!=d2) {
							add(dp[i][u2][z1][d2][z2],r);
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
}






