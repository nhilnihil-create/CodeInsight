#include<bits/stdc++.h>
#define rint register int 
#define ll long long 
#define mk make_pair
using namespace std;
ll ans,N,X;
inline void Solve(ll a,ll b){
	if(b%a==0) {
		ans+=(2ll*b/a-1)*a;
		return ;
	}
	ll t=b/a;
	ans+=2ll*t*a;
	Solve(b%a,a);
}
int main(){
	cin>>N>>X;
	ans=N;
	Solve(min(X,N-X),max(X,N-X));
	cout<<ans;
	return 0;
} 