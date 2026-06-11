#include<bits/stdc++.h>
using namespace std;
const int Max_N=1e5;
int n,a[Max_N*2+5],c[Max_N*2+5],A[Max_N*2+5];
inline bool chck(int x){
	for(int i=1;i<2*n;i++) A[i]=a[i]>=c[x];
	int dis=0;
	for(;n-dis-1>=1&&!(A[n-dis-1]==A[n-dis]||A[n+dis]==A[n+dis+1]);++dis);
	if(A[n-dis-1]==A[n-dis]) return A[n-dis];
	if(A[n+dis+1]==A[n+dis]) return A[n+dis];
	return A[n]==(n&1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<2*n;i++) scanf("%d",&a[i]),c[i]=a[i];
	sort(c+1,c+2*n);
	int l=1,r=2*n-1;
	for(;l<r;){
		int mid=(l+r+1)>>1;
		if(chck(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",c[l]);
	return 0;
}