#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

vector<vector<ll>> C(100,vector<ll>(100,1));
void comb_init(){
  for(int i = 2;i <= 60;i++){
    for(int j = 1;j < i;j++){
      C[i][j] = C[i-1][j-1]+C[i-1][j];
    }
  }
}

int main(){
  
  cout << fixed << setprecision(20);
  comb_init();
  int n,a,b;
  cin >> n >> a >> b;
  vector<pair<ll,int>> v;
  ll res = 0;
  {
    vector<ll> g(n);
    rep(i,n)cin >> g[i];
    sort(ALL(g),greater<ll>());
    v.push_back(make_pair(g[0],1));
    for(int i = 1;i < n;i++){
      if(v.back().first == g[i])v.back().second++;
      else v.push_back(make_pair(g[i],1));
    }
  }
  vector<P> g(100);
  vector<ll> k(100,0);
  for(int i = a;i <= b;i++){
    ll sum = 0;
    int rest = i;
    rep(j,100){
      if(rest <= 0)break;
      if(rest > v[j].second)sum += v[j].first*v[j].second,rest -= v[j].second;
      else sum += v[j].first*rest,g[i] = make_pair(v[j].second,rest),rest = 0;
    }
    k[i] = sum;
  }
  int mx = a;
  for(int i = a;i <= b;i++)if(mx*k[i] > i*k[mx])mx = i;
  cout << 1.0*k[mx]/mx << endl;
  vector<int> pos;
  pos.push_back(mx);
  for(int i = a;i <= b;i++)if(mx != i && mx*k[i] == i*k[mx])pos.push_back(i);
  for(int au : pos)res += C[g[au].first][g[au].second];
  cout << res << endl;

  

  return 0;
}