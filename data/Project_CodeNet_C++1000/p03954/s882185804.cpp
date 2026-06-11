#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
const int maxn=2e5+10;
int a[maxn],b[maxn],ans,n;
bool check(int x){
	rep(i,1,n*2-1) b[i]=a[i]>x;
	for(int i=1,t=b[n];i<n;++i,t^=1) if(b[n-i]==t||b[n+i]==t) return t;
	return b[1];
}
int main(){
	scanf("%d",&n);
	rep(i,1,n*2-1) scanf("%d",&a[i]);
	int l=2,r=2*n-2,ans=n*2-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1,ans=mid;
	}
	printf("%d\n",ans);
	return 0;
}