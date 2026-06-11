#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

int mod=1e9+7;
long long modpow(long long x,long long n,long long mod)
{
  if(n==0)return 1;
  long long res=modpow(x*x%mod,n/2,mod);
  if(n&1)res=res*x%mod;
  return res;
}
long long modinv(long long a,long long m=mod)//extgcdの方がいいらしい
{
  return modpow(a,m-2,m);
}
vector<ll>cal(200001);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h,w,a,b;
  cin>>h>>w>>a>>b;
  cal[0]=1;
  repi(i,1,200001)
  {
    cal[i]=(ll)cal[i-1]*i%mod;
  }
  ll res=0;
  ll tres=cal[h-a-1+b]*cal[a+w-b-1]%mod;
  ll m=min(h-a,w-b);
  rep(i,m)
  {
    res+=(ll)modinv(cal[b+i])*tres%mod*modinv(cal[h-a-1-i])%mod*modinv(cal[a+i])%mod*modinv(cal[w-b-1-i])%mod;
    res%=mod;
  }
  cout<<res<<endl;



  return 0;

}
