#include <bits/stdc++.h>
using namespace std;
int n,a[200009],b[200009],head=1,tail,ans=0;
int judge(int x){
	for(int i=1;i<=2*n-1;i++)
		if(a[i]>=x)	b[i]=1;
		else b[i]=0;
	int ahd=n,fwd=n;
	while(ahd>1&&fwd<2*n-1){
		if(b[ahd]==b[ahd-1])	return b[ahd];
		else if(b[fwd]==b[fwd+1])	return b[fwd];
		ahd--;fwd++;
	}
	for(int i=1;i<n;i++)	b[n]^=1;
	return b[n];
}
int main(){
	scanf("%d",&n);tail=2*n-1;
	for(int i=1;i<=2*n-1;i++)	scanf("%d",&a[i]);
	while(head<=tail){
		int mid=(head+tail)/2;
		if(judge(mid)==1)
			{head=mid+1;ans=max(ans,mid);} 
		else tail=mid-1;
	}
	printf("%d",ans);
	return 0;
}