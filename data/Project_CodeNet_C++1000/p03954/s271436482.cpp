#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
int n,a[200005];
bool check(int mid){
	for (int i=0;i<n-1;i++){
		int s0=0,s1=0;
		if (a[n-i]>=mid&&a[n-i-1]>=mid) s1++;
		if (a[n-i]<mid&&a[n-i-1]<mid) s0++;
		if (a[n+i]>=mid&&a[n+i+1]>=mid) s1++;
		if (a[n+i]<mid&&a[n+i+1]<mid) s0++;
		if (s1) return 1;
		if (s0) return 0;
	}
	return a[1]>=mid;
}
int main(){
	//freopen("mid.in","r",stdin);
	//freopen("mid.out","w",stdout);
	scanf("%d",&n);
	For(i,1,2*n-1) scanf("%d",&a[i]);
	int l=2,r=2*n-1,ans=1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
}