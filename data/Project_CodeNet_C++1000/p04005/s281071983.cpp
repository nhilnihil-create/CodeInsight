#include<iostream>
#include<cstdio> 
#include<algorithm>
using namespace std;
 
long long a[3];
long long ans;
 
 int main() {
 	scanf("%lld%lld%lld",a,a+1,a+2);
 	if((a[0]%2==0)||(a[1]%2==0)||(a[2]%2==0)) {
 		ans=0;
 		printf("%lld\n",ans);
	 }
 	else {
 		sort(a,a+3);
 		ans=a[0]*a[1];
 		printf("%lld\n",ans);
	 }
	 return 0;
 }