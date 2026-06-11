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
int n,m,i,j,l[200005],r[200005],a[200005];
long long ans;
stack<pair<int,int> > stk;
int main()
{
	scanf("%d",&n);
	fz1(i,n){
		scanf("%d",&a[i]);
	}
	fz1(i,n){
		while(!stk.empty()&&stk.top().second>a[i]){
			r[stk.top().first]=i-1;
			stk.pop();
		}
		stk.push(make_pair(i,a[i]));
	}
	while(!stk.empty()){
		r[stk.top().first]=n;
		stk.pop();
	}
	fd1(i,n){
		while(!stk.empty()&&stk.top().second>a[i]){
			l[stk.top().first]=i+1;
			stk.pop();
		}
		stk.push(make_pair(i,a[i]));
	}
	while(!stk.empty()){
		l[stk.top().first]=1;
		stk.pop();
	}
	fz1(i,n){
		ans+=1ll*a[i]*(i-l[i]+1)*(r[i]-i+1);
	}
	cout<<ans<<endl;
	return 0;
}