#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define llmax LLONG_MAX   //ranges are defined in climits
#define llmin LLONG_MIN
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
  lli n;cin>>n;
  lli result=1,mod=1e9+7;
  vector<bool>prime(n+1,true);
  vector<lli>primes;
  for(lli p=2;p*p<=n;p++)
  {
    if(prime[p]==true)
    {
      for(lli i=p*2;i<=n;i+=p)
      {
        prime[i]=false;
      }
    }
  }
  for(int i=2;i<=n;i++)
    if(prime[i])  primes.pb(i);
  
  result=1;
  for(auto prime : primes)
  {
    lli exp=0,p=prime;
    while(p<=n)
    {
      exp += (n/p);
      exp%=mod;
      p*=prime;
    }
    exp%=mod;
    result*=(exp+1);
    result%=mod;
  }
  cout<<result;
	return 0;
}