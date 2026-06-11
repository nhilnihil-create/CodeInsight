#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
int mod = 1000000000+7;

int main(){

	ll x;
	cin>>x;

	ll ans=x/11*2;
	if(x%11>6)ans+=2;
	else if(x%11>0)ans+=1;

	cout<<ans<<endl;

	return 0;
}
