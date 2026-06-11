#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll ans=0;
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	else{
		ans+=b*2*(a/b);
		return gcd(b,a%b);
	}
}
int main()
{
	ll n;ll x;
	cin>>n>>x;
	ans+=x+(n-x);
	ll l=gcd(x,n-x);
	ans-=l;
	cout<<ans<<endl;
	return 0;
}