#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,a,b;
	cin>>n>>a>>b;
	map<ll,ll>c;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		x*=-1;
		c[x]++;
	}
	ll ans=0;
	auto itr=c.begin();
	if(a<=itr->second){
		ll ans1=(itr->first)*(-1)*a;
		double A=a;
		printf("%.9f\n",ans1/A);
		ll lim=min(itr->second,b);
		//cout << lim<<endl;
		ll val=itr->second;
		ll now=itr->second;
		for(ll i=2;i<=a;i++){
			now*=(val-i+1);
			now/=i;
		}
		a++;
		ans=now;
		while(a<=lim){
			now*=(val-a+1);
			now/=a;
			ans+=now;
			a++;
		}
		cout <<ans;
		return 0;
	}
	ll sum=0;
	double num=a;
	while(a>itr->second){
		a-=itr->second;
		sum+=(itr->first)*(-1)*(itr->second);
		itr++;
		//cout <<sum;
	}
	sum+=(itr->first)*(-1)*a;
	printf("%.9f\n",sum/num);
	ll now=1;
		for(ll i=1;i<=a;i++){
			now*=(itr->second-i+1);
			now/=i;
		}	
		cout<<now;
	// your code goes here
	return 0;
}