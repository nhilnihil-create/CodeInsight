#include<bits/stdc++.h>
using namespace std;
int a[100005],cnt;
int n,m,sw1,sw2;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){	
		scanf("%d",&a[i]);
		if (a[i]&1){
			cnt++;
			if (!sw1) sw1=i;
			else sw2=i;
		}
	}
	if (cnt>2){
		puts("Impossible");
		return 0;
	}
	if (sw1) swap(a[1],a[sw1]);
	if (sw2) swap(a[m],a[sw2]);
	for (int i=1;i<=m;i++)
		printf("%d ",a[i]);
	m=max(m,2); a[1]--; a[m]++;
	int tmp=(a[1]?1:2);
	printf("\n%d\n",m+1-tmp);
	for (int i=tmp;i<=m;i++)
		printf("%d ",a[i]);
}