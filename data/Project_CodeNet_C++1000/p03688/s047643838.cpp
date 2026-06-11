#include<bits/stdc++.h>
using namespace std;
int n,a;
int main(){
	scanf("%d",&n);
	int mx=0,mxc,mn=n,mnc;
	for(int i=0,a;i<n;i++){
		scanf("%d",&a);
		if (a>mx)mx=a,mxc=1;
		else if (a==mx)mxc++;
		if (a<mn)mn=a,mnc=1;
		else if (a==mn)mnc++;
	}
	if (mx==mn&&(mx==n-1||mx<=n/2)||mx==mn+1&&mx-mnc>0&&mx-mnc<=mxc/2)puts("Yes");
	else puts("No");
}
