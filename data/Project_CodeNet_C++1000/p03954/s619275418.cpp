#include <bits/stdc++.h>
#define rg register
#define LL long long 

using namespace std;

const int N=200010;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[N];
int l,r,ans;
bool check(int mid){
	for(int i=0;i<n-1;i++){
		if((a[n+i]>mid&&a[n+i+1]>mid)||(a[n-i]>mid&&a[n-i-1]>mid))return false;
		if((a[n+i]<=mid&&a[n+i+1]<=mid)||(a[n-i]<=mid&&a[n-i-1]<=mid))return true;
	}
	return a[1]<=mid;
}
int main()
{
	n=read();
	for(rg int i=1;i<=(n<<1)-1;i++)
		a[i]=read();
	l=1,r=(n<<1)-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}