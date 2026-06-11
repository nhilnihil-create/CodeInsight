#include <bits/stdc++.h>
using namespace std;
const int M=105;
int n,m,a[M],b[M];
bool cmp(int a,int b){
	return (a&1)>(b&1);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	if (m==1){
		if (a[1]==1)
			printf("%d \n%d\n%d",a[1],1,a[1]);
		else
			printf("%d \n%d\n%d %d",a[1],2,a[1]-1,1);
		return 0;
	}
	int t=0;
	for (int i=1;i<=m;i++)
		t+=a[i]&1;
	if (t>2)
		return puts("Impossible"),0;
	sort(a+1,a+m+1,cmp);
	if (a[2]&1)
		swap(a[2],a[m]);
	for (int i=1;i<=m;i++)
		b[i]=a[i];
	int _m=m;
	b[1]++,b[m]--;
	if (b[m]==0)
		_m--;
	for (int i=1;i<=m;i++)
		printf("%d ",a[i]);
	puts("");
	printf("%d\n",_m);
	for (int i=1;i<=_m;i++)
		printf("%d ",b[i]);
	return 0;
}