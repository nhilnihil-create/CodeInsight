#include <iostream>
using namespace std;
typedef long long ll;
ll n,x;
ll ans=0;
int main()
{
	cin>>n>>x;
	ans+=n;
	ll a=max(x,n-x),b=min(x,n-x);
	while(a%b!=0)
	{
		ans+=2*(a/b)*b;
		a=a%b;
		swap(a,b);
	}
	ans+=2*(a/b)*b-b;
	cout<<ans<<endl;
	return 0;
}