#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N],c[N];
int n; 
inline bool solve(int t){
	for(int i=1;i<=n*2-1;i++)b[i]=(a[i]>=t),c[i]=-1;
	for(int i=2;i<=n*2-1;i++)if(b[i]==b[i-1]){
		c[i]=c[i-1]=b[i];
	}
	int mid=n;
	if(~c[mid])return c[mid];
	for(int i=1;i<n;++i){
		if(~c[mid-i])return c[mid-i];
		if(~c[mid+i])return c[mid+i];
	}
	return b[1];
}

int main()
{
	cin >> n;
	for(int i=1;i<=n*2-1;i++)scanf("%d",&a[i]);
	int l=1,r=n*2-1;
	while(l<r){
		int mid=(l+r+1)>>1;
		bool ret=solve(mid);
		if(ret==1) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}