#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define spln(i,n) (i==n?'\n':' ')
using namespace std;
long long n,m,i,j,a[200005],pre[200005],suf[200005],ans;
int main()
{
	scanf("%lld%lld",&n,&m);
	fz1(i,n){
		scanf("%lld",&a[i]);
		pre[i]=pre[i-1]+max(a[i],0ll);
	}
	fd1(i,n){
		suf[i]=suf[i+1]+max(a[i],0ll);
	}
	fz1(i,n){
		a[i]+=a[i-1];
	}
	fz1(i,n-m+1){
		ans=max(ans,a[i+m-1]-a[i-1]+pre[i-1]+suf[i+m]);
		ans=max(ans,pre[i-1]+suf[i+m]);
	}
	cout<<ans<<endl;
	return 0;
}