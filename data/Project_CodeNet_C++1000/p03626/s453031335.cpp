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


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  string s,t;
  cin>>s>>t;
  int id=0;
  int mod=1e9+7;
  ll res=1;
  int pre=0;
  if(s[0]==t[0]){res=3;id++;pre=1;}
  else {res=6;id+=2;pre=0;}
  while(1)
  {
    if(id>=n)break;
    if(s[id]==t[id])
    {
      if(pre)res=res*2%mod;
      id++;
      pre=1;
    }
    else
    {
      if(pre)res=res*2%mod;
      else res=res*3%mod;
      id+=2;
      pre=0;
    }
  }
  cout<<res<<endl;


  return 0;

}
