#include <bits/stdc++.h>
using namespace std;
int n,t,a[100001],mx[100001],s,ans=0;
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;++i)	scanf("%d",a+i);
	mx[n]=a[n];
	for(int i=n-1;i>=0;--i)	mx[i]=max(mx[i+1],a[i]);
	for(int i=1;i<=n;++i){
		if(s<mx[i]-a[i])		s=mx[i]-a[i],ans=1;
		else if(s==mx[i]-a[i])	ans++;
	}
	printf("%d\n",ans);
	return 0;
}