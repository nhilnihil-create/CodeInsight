#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int a[N],n; 
ll l[N],r[N];
int main(){
	scanf("%d",&n);
	priority_queue<int>qr;
	priority_queue<int,vector<int>,greater<int> >ql;
	ll s=0,t=0;
	for(int i=1;i<=3*n;i++){
		scanf("%d",&a[i]);
		if(i<=n) ql.push(a[i]),s+=a[i];
		else if(i<=2*n){
			s+=a[i];
			ql.push(a[i]);
			s-=ql.top();
			ql.pop();
		}
		else {
			qr.push(a[i]),t+=a[i];
		}
		if(i>=n&&i<=2*n) l[i]=s;
	}
	r[2*n+1]=t;
	for(int i=2*n;i>n;i--){
		 t+=a[i];
		 qr.push(a[i]);
		 t-=qr.top();
		 qr.pop();
		 r[i]=t;
	}
	ll ans=-1e15;
	for(int i=n;i<=2*n;i++){
		if(ans<l[i]-r[i+1]) ans=l[i]-r[i+1]; 
	} 
	printf("%lld\n",ans);
	return 0;
}