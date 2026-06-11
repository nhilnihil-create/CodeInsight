#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  ll n,c,k;
  cin >> n >> c >> k;
  priority_queue<ll,vector<ll>,greater<ll>> que;
  vector<ll> t(n);
  rep(i,n)cin >> t[i];
  sort(ALL(t));
  ll res = 0;
  ll hu = 0;
  rep(i,n){
    if(que.empty()){
      que.push(t[i]);
      hu++;
      continue;
    }
    ll cnt = 0;
    while(!que.empty()){
      ll tt = que.top();que.pop();
      if(tt+k < t[i])cnt++;
      else {
        que.push(tt);
        break;
      }
    }
    if(cnt == 0){
      que.push(t[i]);
      hu++;
      continue;
    }
    res += (cnt+c-1)/c;
    hu -= cnt;
    if((cnt%c) != 0)hu = max(hu-(c-cnt%c),0ll);
    while(que.size() != hu)que.pop();
    que.push(t[i]);
    hu++;
  }
  res += (hu+c-1)/c;
  cout << res << endl;



  return 0;
}