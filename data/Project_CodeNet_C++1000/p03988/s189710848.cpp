#include<bits/stdc++.h>
using namespace std;
 
int n,a[109],b[109];
void gg(){
	puts("Impossible"); exit(0);
}
int main(){
	scanf("%d",&n);
	int i,m=0;
	for (i=1; i<=n; i++){
		scanf("%d",&a[i]); b[a[i]]++;
		m=max(m,a[i]);
	}
	for (i=0; i<=m; i++){
		if (!b[max(i,m-i)]) gg();
		b[max(i,m-i)]--;
	}
	int mn=m+3>>1;
	for (i=0; i<mn; i++) if (b[i]) gg();
	puts("Possible");
	return 0;
}