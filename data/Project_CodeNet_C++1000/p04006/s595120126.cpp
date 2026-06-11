#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define drep(i,r,l) for(int i=r;i>=l;--i)
using namespace std;
const int sz=4007;
typedef long long ll;
int n;
int cst;
int a[sz];
ll ans;
deque<int>q;
void insert(int x){
	while(!q.empty()&&a[q.back()]>a[x]) q.pop_back();
	q.push_back(x);
}
int main(){
	ans=1e18;
	scanf("%d%d",&n,&cst);
	rep(i,1,n) scanf("%d",&a[i]),a[i+n]=a[i];
	rep(k,0,n-1){
		ll sum=0;
		while(q.size()) q.pop_back();
		rep(i,n-k+1,n) insert(i);
		rep(i,n+1,2*n){
			while(!q.empty()&&i-q.front()>k) q.pop_front();
			insert(i);
			sum+=a[q.front()];
		}
		ans=min(ans,sum+1ll*k*cst);
	}
	printf("%lld\n",ans);
}