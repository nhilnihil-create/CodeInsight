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
#include <stack>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

struct sieve{
  int p=0;
  vector<bool> furui;
  sieve(int n){
    furui.resize(n,1);
    furui[0]=0;
    furui[1]=0;
    for(int i=2;i<n;i++)if(furui[i])for(int j=i*2;j<n;j+=i)furui[j]=0;
  }
  bool isprime(int m){return furui[m];}
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  ll a,b;cin>>a>>b;
  ll res=0;
  vector<ll>x(n);
  rep(i,n){
    cin>>x[i];
  }
  rep(i,n-1){
    res+=min(b,(x[i+1]-x[i])*a);
  }
  cout<<res<<endl;


  return 0;

}
