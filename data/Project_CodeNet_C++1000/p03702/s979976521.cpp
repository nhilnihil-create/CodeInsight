#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int l=1,r=1e9,n,a[N],A,B;
inline int check(int mid){
	int res=0;
	for(int i=1;i<=n;i++)	if(a[i]>mid*B){
		res+=(a[i]-mid*B+A-B-1)/(A-B);
	}
	return res<=mid;
}
signed main(){
	cin>>n>>A>>B;
	for(int i=1;i<=n;i++)	cin>>a[i];
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))	r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}
