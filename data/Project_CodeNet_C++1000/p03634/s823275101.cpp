#include "bits/stdc++.h"

#define MOD 1000000007
#define rep(i, n) for(ll i=0; i < (n); i++)
#define ALL(v) v.begin(),v.end()
#define DUMP(i, v)for(ll i=0;i<v.size();i++)cout<<v[i]<<" "

using namespace std;
typedef long long int ll;
typedef vector<ll> llvec;
typedef vector<double> dvec;
typedef pair<int, int> P;
struct Edge{ll from, to, cost;};

ll mod(ll a, ll mod){
  ll res = a%mod;
  if(res<0)res=res + mod;
  return res;
}

ll modpow(ll a, ll n, ll mod){
  ll res=1;
  while(n>0){
    if(n&1) res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll modinv(ll a, ll mod){
  return modpow(a, mod-2, mod);
}

bool is_prime(ll n){
  ll i = 2;
  if(n==1)return false;
  if(n==2)return true;
  bool res = true;
  while(i*i <n){
    if(n%i==0){
      res = false;
    }
    i = i+1;
  }

  //if(i==1)res = false;
  if(n%i==0)res=false;
  return res;
}

vector<P> G[101000];
ll N, K, Q;
map<ll, ll> dist;

void gen_dist(ll f, ll c){
  ll S = G[c].size();
  rep(i, S){
    ll v = G[c][i].first;
    ll cost = G[c][i].second;
    if(v==f)continue;
    dist[v] += dist[c] + cost;
    gen_dist(c, v);
  }
}

/**************************************
** A main function starts from here  **
***************************************/
int main(){
  cin >> N;
  rep(i, N-1){
    ll a, b, c;
    cin >> a >> b >> c;
    //if(a>b)swap(a,b);
    a--;b--;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }

  cin >> Q >> K;
  K--;
  dist[K] = 0;
  gen_dist(-10, K);
  llvec x(Q, 0);
  llvec y(Q, 0);
  rep(i, Q){
    cin >> x[i] >> y[i];
    x[i]--;y[i]--;
  }

  rep(i, Q){
    cout << dist[x[i]] + dist[y[i]] << endl;
  }
  return 0;
}
