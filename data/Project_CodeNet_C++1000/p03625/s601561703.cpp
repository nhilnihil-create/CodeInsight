#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
  
int main()
{
  ll N;
  cin >> N;
  map<ll,ll> mp;

  vector<ll> A(N);
  REP(i, N){
    cin >> A[i];
    mp[A[i]]++;
  }
  ll MAX4 = 0;
  ll MAX2[2]={0};
  ll a=0,b=0;
  for(auto x:mp){
    if(x.second>=2){
      if(MAX2[0]<x.first){
        MAX2[1]=MAX2[0];
        MAX2[0]=x.first;
      }
      a++;
    }
    if(x.second>=4){
      MAX4=max(MAX4,x.first);
      b++;
    }
  }

  ll ans = 0;
  if(a<2&&b<1){
    cout << 0 << endl;
  }else{
    cout << max(MAX4*MAX4,MAX2[0]*MAX2[1]) << endl;
  }
}