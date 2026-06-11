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
int n,m,i,j,vis[200005],a[200005];
int main()
{
	scanf("%d%d",&n,&m);
	if(m==1||m==n+n-1){
		puts("No");
		return 0;
	}
	puts("Yes");
	if(m!=2){
		a[n]=m;
		a[n+1]=n*2-1;
		a[n-1]=1;
		a[n+2]=2;
		vis[m]=vis[n*2-1]=vis[1]=vis[2]=1;
		j=1;
		fz1(i,n*2-1)if(!a[i]){
			while(vis[j])j++;
			vis[j]=1;a[i]=j;
		}
	}
	else{
		a[n]=m;
		a[n+1]=1;
		a[n-1]=n*2-1;
		a[n+2]=n*2-2;
		vis[m]=vis[1]=vis[n*2-1]=vis[n*2-2]=1;
		j=1;
		fz1(i,n*2-1)if(!a[i]){
			while(vis[j])j++;
			vis[j]=1;a[i]=j;
		}
	}
	fz1(i,n*2-1){
		printf("%d ",a[i]);
	}
	return 0;
}