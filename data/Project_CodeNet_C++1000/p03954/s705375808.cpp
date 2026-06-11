#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
const int inf=1e9+10; 
int n,a[N],b[N],ans;
int l,r,mid;
bool small(int x,int y,int q){
	return a[x]<=q && a[y]<=q;
}

bool big(int x,int y,int q){
	return a[x]>q && a[y]>q;
}

bool check(int x){
	for(int i=0;i<n-1;i++){
		if(small(n+i,n+i+1,x) || small(n-i,n-i-1,x)) return true;
		if(big(n+i,n+i+1,x) || big(n-i,n-i-1,x)) return false;
	}
	return a[1]<=x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++) scanf("%d",&a[i]);
	l=1; r=2*n-1;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}