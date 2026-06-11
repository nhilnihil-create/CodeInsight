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
int n,m,i,j,a[250005],lim[505];
queue<int> tp;
struct ii
{
	int x,id;
}b[505];
bool cmp(ii x,ii y)
{
	return x.x<y.x;
}
int main()
{
	scanf("%d",&n);
	fz1(i,n){
		b[i].id=i;
		scanf("%d",&b[i].x);
		lim[i]=b[i].x;
	}
	sort(b+1,b+n+1,cmp);
	fz1(i,n){
		if(a[b[i].x]){
			puts("No");
			return 0;
		}
		int c=b[i].id-1;
		fz1(j,b[i].x-1){
			if(c&&!a[j]){
				a[j]=b[i].id;
				c--;
			}
		}
		if(c){
			puts("No");
			return 0;
		}
		a[b[i].x]=b[i].id;
		fz1(j,n-b[i].id)tp.push(b[i].id);
	}
	fz1(i,n*n)if(a[i]==0){
		a[i]=tp.front();tp.pop();
		if(i<lim[a[i]]){
			puts("No");
			return 0;
		}
	}
	cout<<"Yes\n";
	fz1(i,n*n)cout<<a[i]<<' ';
	return 0;
}