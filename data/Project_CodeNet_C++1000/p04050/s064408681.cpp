#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef bool bl;
typedef vector<bl> vb;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;

const ll e5 = 1 << 20;
const ll mod = 1000003;
const ll e3 = 1 << 13;
const ll INF = 1ll << 60;

ll n,m;
ll a[e5];
vl o;
vl e;

void error(){
  cout << "Impossible" << endl;
  exit(0);
}

int main(){
  cin >> n >> m;
  for(ll i = 0;i < m;i++) cin >> a[i];
  for(ll i = 0;i < m;i++){
    if(a[i]%2 == 1){
      o.push_back(a[i]);
    }else{
      e.push_back(a[i]);
    }
  }
  if(m == 1){
    vl ans;
    cout << abs(a[0]) << endl;
    if(a[0]-1 > 0) ans.push_back(a[0]-1);
    ans.push_back(1);
    cout << ans.size() << endl;
    for(ll i = 0;i < ans.size()-1;i++){
      cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1] << endl;
    return 0;
  }
  if(o.size() > 2) error();
  else if(o.size() == 2){
    cout << o[0] << " ";
    for(ll x : e){
      cout << x << " ";
    }
    cout << o[1] << endl;
  }else if(o.size() == 1){
    for(ll x : e){
      cout << x << " ";
    }
    cout << o[0] << endl;
  }else{
    for(ll i = 0;i < e.size()-1;i++) cout << e[i] << " ";
    cout << e[e.size()-1] << endl;
  }
  vl ans;
  if(o.size() == 2){
    ll x = o[0]-1;
    if(x > 0) ans.push_back(x);
    for(ll i = 0;i < e.size();i++){
      ans.push_back(e[i]);
    }
    ans.push_back(o[1]+1);
  }else if(o.size() == 1){
    ans.push_back(e[0]-1);
    for(ll i = 1;i < e.size();i++){
      ans.push_back(e[i]);
    }
    ans.push_back(o[0]+1);
  }else{
    ans.push_back(e[0]-1);
    for(ll i = 1;i < e.size()-1;i++){
      ans.push_back(e[i]);
    }
    ans.push_back(e[e.size()-1]+1);
  }
  cout << ans.size() << endl;
  for(ll i = 0;i < ans.size()-1;i++){
    cout << ans[i] << " ";
  }
  cout << ans[ans.size()-1] << endl;




}
