#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
struct p{
	ll l,r;
}a[N];
ll s;
int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		a[i].l=x,a[i].r=a[i].l+t;
	}
	ll l=a[1].l,r=a[1].r;
	for(int i=2;i<=n;i++){
		if(a[i].l<=r) r=a[i].r;
		else s+=r-l,l=a[i].l,r=a[i].r;
	}
	s+=r-l;
	printf("%lld\n",s);
	return 0;
}