#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
bool isPrime(int i)
{
	if(i==1)return false;
	if(i==2) return true;
	if(i%2==0) return false;
	for(int j=3;j*j<=i;j++)
	{
		if(i%j==0) return false;
	}
	return true;
}
long long n,ans=1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(isPrime(i))
		{
			long long t=i;
			long long sum=0;
			while(n/t!=0)
			{
				sum+=n/t;
				t*=i;
				sum%=mod;
			}
			ans*=((sum+1)%mod);
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}

