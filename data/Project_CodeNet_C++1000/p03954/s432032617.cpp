#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#define SF scanf
#define PF printf
#define MAXN 200010
using namespace std;
int n,m;
int a[MAXN],b[MAXN];
bool check(int x){
	for(int i=1;i<=m;i++)
		b[i]=(a[i]>=x);
	for(int i=0;i<n-1;i++){
		if(b[n+i]==b[n+i+1])
			return b[n+i];
		if(b[n-i]==b[n-i-1])
			return b[n-i];
	}
	return b[1];
}
int main(){
	SF("%d",&n);
	m=2*n-1;
	for(int i=1;i<=m;i++)
		SF("%d",&a[i]);
	int l=1,r=m,ans=m;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else
			r=mid-1;
	}
	PF("%d",ans);
}