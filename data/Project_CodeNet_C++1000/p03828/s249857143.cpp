#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

const int mod=1e9+7;
const int inf=-1;
const int sz=2e5;

#define pi acos(-1)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define gap ' '
#define lb lower_bound
#define ub upper_bound
#define clr(x) memset(x,0,sizeof(x))
#define all(x) sort(x.begin(),x.end())
#define rall(x) reverse(x.begin(),x.end())
#define dbg puts("finding wrong")
#define case(x,y) printf("Case %lld: %lld\n",++x,y)
#define fastio ios::sync_with_stdio(false);cin.tie(0)

const int m=1e6;
vector <int> prime;
bool sieve[m+2];
 
void primeSieve () {
    memset(sieve, true, sizeof(sieve));
 
    sieve[0]=sieve[1]=false;
 
    prime.push_back(2);
    for (int i = 4; i <=m; i += 2 ) sieve[i]=false;
 
    int sqrtn = sqrt (m);
    for ( int i = 3; i <= sqrtn; i += 2 ) {
        if (sieve[i]) {
            for (ll j = i * i; j <=m; j += 2 * i ) sieve[j]=false;
        }
    }
 
    for ( int i = 3; i <=m; i += 2 ) if (sieve[i]) prime.push_back(i);
}


int ar[sz];

int main()
{
  primeSieve();
  fastio;
  ll t, a, b, c, ans=1, i, n;
  
  cin>>n;
  
  for(i=0; i<prime.size(); i++)
  {
      ll res=0;
      a=n;
      if(prime[i]>n)break;
      while(a>0)
      {
          res+=(a/prime[i]);
          res=res%mod;
          a/=prime[i];
      }
      ans=(ans%mod*(res+1))%mod;
  }
  
  cout<<ans<<endl;
  
}
