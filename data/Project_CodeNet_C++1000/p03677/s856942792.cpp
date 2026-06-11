#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define ll long long
using namespace std;

int n, m, x, y, d, p;
ll s[N], s1[N], s2[N], mn;

inline void ins(int L, int R, int x, int f){
	if(!f){s[L]+=x; s[R+1]-=x; return;}
	s[L]+=x; s[R+1]-=x;
	s1[L+1]--; s1[R+1]++; s2[R+1]+=R-L;
}

int main(){
	scanf("%d%d", &m, &n);
	scanf("%d", &x);
	for(int i=2; i<=m; i++){
		scanf("%d", &y);
		if(x<=y){
			d=y-x;
			ins(1, x, d, 0);
			ins(x+1, y, d, -1);
			if(y<=n-1)ins(y+1, n, d, 0);
		}else{
			d=n-x+y; p=x%n+1;
			if(p==1){ins(1, y, y, -1); ins(y+1, x, d, 0);}
			else{ins(1, y, y, -1); ins(p, n, d, -1); ins(y+1, x, d, 0);}
		}
		x=y;
	}
	for(int i=1; i<=n; i++)s[i]+=s[i-1];
	for(int i=1; i<=n; i++)s1[i]+=s1[i-1];
	for(int i=1; i<=n; i++)s1[i]+=s1[i-1]+s2[i];
	for(int i=1; i<=n; i++)s[i]+=s1[i];
	mn=s[1]; for(int i=2; i<=n; i++)mn=min(mn, s[i]);
	printf("%lld", mn);
	return 0;
}