#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  string A;
  cin >> A;

  ll N = A.size();
  map<char,ll> mp;
  REP(i,N){
    mp[A[i]]++;
  }

  ll cnt = N;
  ll ans = 0;
  for(auto x:mp){
    cnt-=x.second;
    ans+=x.second*cnt;
  }

  cout << ans+1 << endl;
}