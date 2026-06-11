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
int n,m,i,j,a[100005];
long long sum,uit;
int main()
{
	cin>>n;uit=1ll*n*(n+1)/2;
	fz1(i,n){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%uit!=0){
		puts("NO");
		return 0;
	}
	sum/=uit;
	a[0]=a[n];
	fd1(i,n){
		a[i]=a[i]-a[i-1];
	}
	fz1(i,n){
		a[i]-=sum;
	}
	fz1(i,n){
		if(a[i]>0||(-a[i])%n!=0){
			puts("NO");
			return 0;
		}
		sum-=(-a[i])/n;
	}
	if(sum==0) puts("YES"); else puts("NO");
	return 0;
	
	return 0;
}