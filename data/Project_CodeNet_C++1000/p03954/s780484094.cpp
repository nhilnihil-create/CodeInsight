#include<bits/stdc++.h>
using namespace std;
int n,l,r,a[200005];
int pd(int x,int k){
	if ((a[x]>=k)&&(a[x+1]>=k))return 1;
	if ((a[x]<k)&&(a[x+1]<k))return -1;
	return 0;
}
bool check(int k){
	for(int i=0;i<n;i++){
		if (pd(n-i-1,k))return (pd(n-i-1,k)+1)/2;
		if (pd(n+i,k))return (pd(n+i,k)+1)/2;
	}
	return a[1]>=k;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<2*n;i++)scanf("%d",&a[i]);
	l=1,r=2*n-1;
	while (l<r){
		int mid=(l+r+1>>1);
		if (check(mid))l=mid;
		else r=mid-1;
	}
	printf("%d",l);
}