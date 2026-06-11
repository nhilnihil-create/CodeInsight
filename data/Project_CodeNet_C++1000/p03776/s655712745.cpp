#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n+1;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;
typedef pair<int,int> P;

ll comb(ll a,ll b){
  if(b == 1) return a;
  return a*comb(a-1,b-1)/b;
}

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  map<ll,ll> mp;
  rep(i,n){
    cin >> v[i];
    mp[v[i]] ++;
  }
  stack<pair<ll,int>> q;
  for(auto p : mp) q.push(p);
  sort(v);
  reverse(v);
  ll maxsum = 0;
  rep(i,a) maxsum += v[i];
  double maxave = (double)maxsum/a;
  cout << setprecision(10) << maxave << endl;
  ll qts = q.top().second;
  if(a <= qts){
    ll ans = 0;
    ll reach = min(b,qts);
    for(ll i=a;i<=reach;i++){
      ans += comb(qts,i);
    }
    cout << ans << endl;
    return 0;
  }
  ll ans = 0;
  while(!q.empty()){
    auto now = q.top();
    q.pop();
    if(a > now.second){
      a -= now.second;
      b -= now.second;
      continue;
    }
    ans = comb(now.second,a);
    cout << ans << endl;
    return 0;
  }
}