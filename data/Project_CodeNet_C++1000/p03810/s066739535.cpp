#include <bits/stdc++.h>
using namespace std;
int n,a[100009],sum=0,yes=true;
int pre(){
	for(int i=1;i<=n;i++)	if(a[i]%2==1){a[i]--;break;}
	int ngcd=a[1];sum=0;yes=true;
	for(int i=2;i<=n;i++)	ngcd=__gcd(a[i],ngcd);
	for(int i=1;i<=n;i++){
		a[i]/=ngcd;
		if(a[i]%2==0)	sum++;
		if(a[i]==1)	yes=false;
	}
	if(sum%2==1)	return 1;
	else if(n-sum==1&&yes)	return pre()^1;
	else return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]%2==0)	sum++;
		if(a[i]==1)	yes=false;
	}
	if(sum%2==1)	printf("First");
	else if(n-sum==1&&yes)	printf(pre()^1?"First":"Second");
	else printf("Second");
	return 0;
}