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
ll a[100000];
ll b[100000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	ll sum=0;
	ll cnt=0;
	for(int i=0;i<n;i++)
		sum+=a[i];
	cnt=(ll)(n+1)*(ll)n/2LL;
	if(sum%cnt!=0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cnt=sum/cnt;//何回で構築できるか
	bool ans=true;
	for(int i=0;i<n;i++)
	{
		int prev=i-1;
		if(i==0)
			prev=n-1;
		ll dif=a[i]-a[prev];
		if(!((cnt-dif)%(ll)n==0LL && cnt-dif>=0))
			ans=false;
		b[i]=(cnt-dif)/(ll)n;
	}
	if(!ans)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	ll tmp=0;
	for(int i=0;i<n;i++)
		tmp+=b[i];
	if(tmp==cnt)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}