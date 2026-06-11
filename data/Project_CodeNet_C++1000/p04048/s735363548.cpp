#include<bits/stdc++.h>
#define re register
#define inc(i,j,k) for(re int i=head[u];i;i=e[i].nxt)
#define ll long long
using namespace std; 
ll n,x,ans;
void work(ll x,ll y){
	if(x%y==0){
		ans+=2*x-y;
		return; 
	}
	else{
		ans+=2*(x-x%y);
		work(y,x%y);
	}
}
int main(){
	scanf("%lld%lld",&n,&x);
	ans=n;
	n-=x;
	work(max(n,x),min(n,x));
	printf("%lld",ans);
}