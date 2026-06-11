#include<bits/stdc++.h>
using namespace std;
int n,a[20000010];
int small(int i,int j,int k) {
	return a[i]<=k&&a[j]<=k;
}
int big(int i,int j,int k){
	return a[i]>k&&a[j]>k;
} 
int check(int k){
	for(int i=0;i<n-1;i++){
		if (big(n+i,n+i+1,k)||big(n-i,n-i-1,k))
			return 0;
		if (small(n+i,n+i+1,k)||small(n-i,n-i-1,k))
			return 1;
	}
	return small(1,1,k);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++)
		scanf("%d",&a[i]);
	int l=1,r=2*n-1,ans;
	while (l<r){
		int mid=l+r>>1;
		if (check(mid)) r=mid;
			else l=mid+1;
	}
	printf("%d\n",r);
	return 0; 
}