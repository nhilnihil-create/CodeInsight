#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
ll n,k,a,s,ans,tr[200005];
pair<ll,ll> b[200005];
ll sum(ll p){
	ll res=0;
	while(p)res+=tr[p],p-=p&-p;
	return res;
}
void add(ll p){
	while(p<=n+1)tr[p]++,p+=p&-p;
}
int main(){
	n=read(),k=read();
	for(ll i=1;i<=n;i++){
		a=read();
		s+=a;
		b[i]={s-k*i,i};
	}
	sort(b,b+n+1);
	for(ll i=0;i<=n;i++){
		ans+=sum(b[i].second);
		add(b[i].second+1);
	}
	cout << ans;
	return 0;
}