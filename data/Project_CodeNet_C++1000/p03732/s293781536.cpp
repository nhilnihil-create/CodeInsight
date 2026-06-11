#include "bits/stdc++.h"

#define MOD 1000000007
#define rep(i, n) for(ll i=0; i < (n); i++)
#define rrep(i, n) for(ll i=(n)-1; i >=0; i--)
#define ALL(v) v.begin(),v.end()
#define rALL(v) v.rbegin(),v.rend()
#define FOR(i, j, k) for(ll i=j;i<k;i++)
#define debug_print(var) cerr << #var << "=" << var <<endl;
#define DUMP(i, v)for(ll i=0;i<v.size();i++)cerr<<v[i]<<" "
#define fi first
#define se second

using namespace std;
typedef long long int ll;
typedef vector<ll> llvec;
typedef vector<double> dvec;
typedef pair<ll, ll> P;
typedef long double ld;
struct edge{ll x, c;};

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
  ll b=mod, u=1, v=0;
  while(b){
    ll t=a/b;
    a-=t*b; swap(a, b);
    u-=t*v; swap(u, v);
  }
  u%=mod;
  if(u<0)u+=mod;
  return u;
}

ll gcd(ll a, ll b){
  ll r = a%b;
  if(r==0) return b;
  else return gcd(b, a%b);
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
/**************************************
** A main function starts from here  **
***************************************/
int main(){
  ll N, W;
  cin >> N >> W;
  llvec w(N), v(N);
  rep(i, N)cin >> w[i] >> v[i];

  vector<llvec> v2(4);
  rep(i, N){
    v2[w[i]-w[0]].push_back(v[i]);
  }
  rep(i, 4)sort(rALL(v2[i]));

  vector<llvec> S(4);
  rep(i, 4){
    S[i]=llvec(v2[i].size()+1, 0);
    rep(j, v2[i].size()){
      S[i][j+1] = S[i][j] + v2[i][j];
    }
  }
  ll ans = 0;
  rep(i, v2[0].size()+1){
    rep(j, v2[1].size()+1){
      rep(k, v2[2].size()+1){
        rep(l, v2[3].size()+1){
          if(w[0]*(i+j+k+l)+j+2*k+3*l>W)break;
          ans = max(ans, S[0][i] + S[1][j] + S[2][k] + S[3][l]);
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
