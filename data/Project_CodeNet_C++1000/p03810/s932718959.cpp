#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define ll long long
using namespace std;
int n, a[N];
inline int gcd(int a, int b){return b?gcd(b, a%b):a;}
inline int solve(){
	ll s=0; int sum, p, g;
	for(int i=1; i<=n; i++)s+=a[i];
	s-=n; if(s&1)return 1;
	sum=p=0; for(int i=1; i<=n; i++)if(a[i]&1){sum++; p=i;}
	if(sum>=2)return 0;
	if(a[p]==1)return 0;
	a[p]--; g=0;
	for(int i=1; i<=n; i++)g=gcd(g, a[i]);
	for(int i=1; i<=n; i++)a[i]/=g;
	return solve()^1;
}
int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++)scanf("%d", &a[i]);
	if(solve())printf("First"); else printf("Second");
	return 0;
}