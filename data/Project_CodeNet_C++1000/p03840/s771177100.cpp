#include <bits/stdc++.h>
using namespace std;
int a[8];
int main (){
	for (int i=1;i<=7;i++) scanf ("%d",&a[i]);long long ans=0;
	if (((a[1]&1)+(a[4]&1)+(a[5]&1)>=2)&&(a[1]&&a[4]&&a[5])) ans+=3,a[1]--,a[4]--,a[5]--;
	printf ("%lld",ans+a[2]+a[1]/2*2ll+a[4]/2*2+a[5]/2*2);
	return 0;
}
