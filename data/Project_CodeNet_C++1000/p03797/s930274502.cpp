#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
int mod = 1000000000+7;

int main(){

	ll n,m;
	cin>>n>>m;

	ll ans=0;
	if(n/2>=m)ans=m/2;
	else {
		ans+=min(n,m/2);
		m-=2*n;
		if(m>0)ans+=m/4;
	}

	cout<<ans<<endl;

	return 0;
}
