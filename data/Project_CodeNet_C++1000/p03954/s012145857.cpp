#include<bits/stdc++.h>
using namespace std;
int n,N,a[2001000];
bool check_big(int x,int k){
	return (a[x+1]>k)&(a[x]>k);
}
bool check_small(int x,int k){
	return (a[x+1]<=k)&(a[x]<=k);
}
bool check(int k){
	for(int i=0;i<N-1;i++){
		if(check_big(N-i-1,k)||check_big(N+i,k)){
			return 0;
		}
		if(check_small(N-i-1,k)||check_small(N+i,k)){
			return 1;
		}
	}
	return (a[1]<=k);
}
int main(){
//	freopen("pyramid.in","r",stdin);
//	freopen("pyramid.out","w",stdout);
	cin>>N;
	n=N*2-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int l=1,r=n;
	while(l+1<r){
		int m=(l+r)/2;
		if(check(m)){
			r=m;
		}
		else{
			l=m;
		}
	}
	cout<<r;
	return 0;
}