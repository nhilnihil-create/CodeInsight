#include <bits/stdc++.h>
#define N 1000005
#define oo 999999999

using namespace std;

int n,m;
int a[N],b[N];
int l=oo,r;
int ans;

bool check(int);

int main(){
	scanf("%d",&n);m=2*n-1;
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]),l=min(l,a[i]),r=max(r,a[i]);	
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<l-1<<endl;
	return 0;
}
bool check(int x){
	memset(b,0,sizeof(b));	
	int z=oo,sum=0,y;
	for(int i=1;i<=m;i++)
		if(a[i]>=x)
			b[i]=1,sum++;
	for(int i=n;i>1;i--)
		if(b[i]==b[i-1]&&z>n-i){	
			z=n-i;
			y=b[i];
		}
	for(int i=n;i<m;i++)
		if(b[i]==b[i+1]&&z>i-n){
			z=i-n+1;
			y=b[i];
		}
	if(z==oo)
		return sum<m-sum?false:true;
	return y?true:false;
}
