#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],num;
int cmp(int x,int y){
	return (x&1)>(y&1);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)scanf("%d",&a[i]),num+=a[i]&1;
	if (num>2){
		puts("Impossible");
		return 0;
	}
	if (m==1){
		if (n==1)puts("1\n1\n1");
		else printf("%d\n%d\n%d %d",a[0],2,a[0]-1,1);
		return 0;
	}
	sort(a,a+m,cmp);
	for (int i=0;i<m;i++)printf("%d ",a[(i+1)%m]);
	puts("");
	a[0]++;a[1]--;
	if (!a[1]){
		printf("%d\n",m-1);
		for (int i=2;i<m;i++)printf("%d ",a[i]);
		printf("%d\n",a[0]);
		return 0;
	}
	printf("%d\n",m);
	for (int i=0;i<m;i++)printf("%d ",a[(i+1)%m]);
}