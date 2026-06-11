#include<cstdio>
#include<algorithm>
#define _rep(i,s,t) for(register int i=s;i>=t;--i)
#define rep(i,s,t) for(register int i=s;i<=t;++i)
using namespace std;
int ans;
const int N=5e5+11;
int n;
int a[N];
inline bool check(int x){
	rep(i,0,n-2){
		if(a[n+i]>=x&&a[n+i+1]>=x||a[n-i]>=x&&a[n-i-1]>=x)return 1;
		if(a[n+i]<x&&a[n+i+1]<x||a[n-i]<x&&a[n-i-1]<x)return 0;
	}
	return a[n+n-1]>=x;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n+n-1)
		scanf("%d",a+i);
	_rep(i,30,0)
		if(check(ans|(1<<i)))
			ans|=(1<<i);
	printf("%d\n",ans);
	return 0;
}