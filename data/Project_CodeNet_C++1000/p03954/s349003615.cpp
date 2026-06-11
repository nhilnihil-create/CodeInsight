#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],b[N],c[N];
int pd(int x){
	for (int i=1;i<=n;i++)c[i]=(a[i]>=x);
	int gol=m,gor=m;
	while ((gol>1)&&(c[gol]!=c[gol-1]))gol--;
	while ((gor<n)&&(c[gor]!=c[gor+1]))gor++;
	if (c[gol]!=c[gor]){
		if (gol+1<=m)gol++;
		else gor--;
	}
	int k=((gol+gor)>>1);
	if ((gol<=m)&&(m<k))return c[gol-1];
	if ((k<m)&&(m<=gor))return c[gor+1];
	return c[gol];
}
int main(){
	scanf("%d",&m);
	n=m*2-1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int l=1,r=n;
	while (l<r){
		int mid=(l+r+1)/2;
		if (pd(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",b[l]);
	return 0;
}