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
int n,x,a[110],t;
int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&x),++a[x],t=max(t,x);
	if(t&1){
		int mid=t+1>>1;
		if(a[mid]^2) return puts("Impossible"),0;
		rep(i,1,mid-1) if(a[i]) return puts("Impossible"),0;
		rep(i,mid+1,t) if(a[i]<2) return puts("Impossible"),0;
		puts("Possible");
	}
	else{
		int mid=t>>1;
		if(a[mid]^1) return puts("Impossible"),0;
		rep(i,1,mid-1) if(a[i]) return puts("Impossible"),0;
		rep(i,mid+1,t) if(a[i]<2) return puts("Impossible"),0;
		puts("Possible");
	}
	return 0;
}