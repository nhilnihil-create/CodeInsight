#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int c[N];
int main(){
	int n,a,b;scanf("%d%d%d",&n,&a,&b);
	ll s=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=2;i<=n;i++){
		ll d=c[i]-c[i-1];
		if(d*a<=b) s+=d*a;
		else s+=b;
	}
	printf("%lld\n",s);
	return 0;
}