#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const string EMP = " ";
const ll INF = 1LL<<60;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main(){
  int n; cin >> n;
  map<ll,int> mp;
  for(int i = 0; i < n; i++){
    ll now; cin >> now;
    if(mp[now] == 1) mp[now]--;
    else mp[now]++;
  }
  int ans = 0;
  for(P p: mp){
    if(p.second == 1) ans++;
  }
  cout << ans << endl;
  return 0;
}
