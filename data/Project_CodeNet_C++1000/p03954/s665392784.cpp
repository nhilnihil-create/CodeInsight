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
using namespace std;
int n,m,i,j,l,r,mid,ans,a[200005],b[200005];
bool check(int x)
{
	int i,j;
	fz1(i,n+n-1){
		b[i]=(a[i]>=x);
	}
	i=j=n;
	while(j<n+n){
		i--;j++;
		if(b[i]==b[i+1]) return b[i];
		if(b[j]==b[j-1]) return b[j];
	}
	return b[n]^((n-1)&1);
}
int main()
{
	scanf("%d",&n);
	fz1(i,n+n-1){
		scanf("%d",&a[i]);
	}
	l=1;r=n+n;
	while(l<r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid;
	}
	cout<<ans<<endl;
	return 0;
}