#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,a[N],mn=1e5,mx,nn;
void fail(){puts("No");exit(0);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mn=min(mn,a[i]),mx=max(mx,a[i]);
	if(mx-mn>1)fail();
	if(mx>mn){
		for(int i=1;i<=n;i++)if(a[i]==mn)nn++;
		if(nn+1>mx||nn==n-1)fail();
		nn+=(n-nn)/2;if(nn<mx)fail();
		puts("Yes");
	}
	else{
		if(mx!=n-1&&n/2<mx)fail();
		puts("Yes");
	}
	return 0;
}