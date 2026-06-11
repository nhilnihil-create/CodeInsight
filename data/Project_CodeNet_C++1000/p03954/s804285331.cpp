#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,i,l,r,mid,a[200005],b[200005],max1,ans,ll,rr;
int read(){
	int xx=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	return xx;
}
int che(int x){
	for(i=1;i<=m;i++)
		if(a[i]>=x)
			b[i]=1;
		else
			b[i]=0;
	ll=0;rr=m+1;
	for(i=n;i>=2;i--)
		if(b[i]==b[i-1]){			
			ll=i;
			break;
		}
	for(i=n;i<=m-1;i++)
		if(b[i]==b[i+1]){
			rr=i;
			break;
		}
	if(ll==0&&rr==m+1)
		return b[1];
	if(ll==0)
		return b[rr];
	if(rr==m+1)
		return b[ll];
	if(n-ll<rr-n)
		return b[ll];
	else
		return b[rr];
}
int main(){
	n=read();m=(n<<1)-1;
	for(i=1;i<=m;i++){
		a[i]=read();
		max1=max(max1,a[i]);
	}
	l=1;r=max1;mid=(l+r)/2;
	while(l<=r){
		if(che(mid)==1){
			ans=max(ans,mid);
			l=mid+1;
		}
		else	
			r=mid-1;
		mid=(l+r)/2;
	}
	cout<<ans<<endl;
	return 0;
}