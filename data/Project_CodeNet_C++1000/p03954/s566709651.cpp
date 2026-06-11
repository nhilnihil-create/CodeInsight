#include<stdio.h>
const int maxn=1000005;
int i,j,k,m,n,l,r;
int a[maxn];
int check(int x){
	for(int i=n,j=n;i>1&&j<m;i--,j++){
		if((a[i]<=x&&a[i-1]<=x)||(a[j]<=x&&a[j+1]<=x))
			return 1;
		if((a[i]>x&&a[i-1]>x)||(a[j]>x&&a[j+1]>x))
			return 0;
	}
	return a[1]<=x;
}
int main(){
	scanf("%d",&n);
	m=(n<<1)-1;
	for(i=1;i<=m;i++)
		scanf("%d",&a[i]);
	l=0,r=m+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}