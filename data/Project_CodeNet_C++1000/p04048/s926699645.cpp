#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll fnc(ll a,ll b){
	if(b==0) return 0;
	else{
		if(a%b==0) return 2*(a/b)*b-b;
		else return 2*b*(a/b)+fnc(b,a%b);
	}
}

int main(){
	ll n,m,ans=0;
	cin>>n>>m;
	ans=n+fnc(n-m,m);
	cout<<ans<<endl;
}
