//金字塔
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n,a[2000001];
bool check(int x){
	int tmp=0;
	for(int i=1;i<n;i++)
		if(a[i]>=x&&a[i+1]>=x)
			tmp=i+1;
	if(tmp==n)return true;
	if(tmp){
		for(int j=tmp;a[j+2]>=x&&j<=2*n-3;j+=2,tmp++);
		if(tmp>=n)return true;
	} //从左往右
	tmp=0;
	for(int i=2*n-1;i>n;i--)
		if(a[i]>=x&&a[i-1]>=x)
			tmp=i-1;
	if(tmp==n) return true;
	if(tmp){
		for(int j=tmp;a[j-2]>=x&&j>=3;j-=2,tmp--);
		if(tmp<=n) return true;
	} //从右往左
	tmp=0;
	for(int i=1;i<=2*n-1;i+=2)
		if(a[i]<x)tmp=1;
	if(!tmp)return true; //特判10101
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++)
		scanf("%d",&a[i]);
	int l=2,r=2*n-2,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)) l=mid+1;
			else r=mid-1;
	}
	printf("%d\n",l-1);
	return 0;
}