#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 1120000000
#define MOD 1000000007

long mod_pow(long x, long n, long p=MOD){
  if(x==0) return 0;
  long res=1;
  x %= p;
  while(n>0){
    if(n&1) res=res*x%p;
    x=x*x%p;
    n>>=1;
  }
  return res;
}
long mod_inv(long x, long p=MOD){ return mod_pow(x%p, p-2, p); }


int main(){
  long n;
  cin>>n;
  string str;
  cin>>str;
  long m = str.size();

  auto prev = vector<long>(n+1, 0);
  prev[0] = 1;

  rep(i,n){
    auto nxt = vector<long>(n+1, 0);
    rep(j,n) if(prev[j]){
      if(j==0) nxt[j] += prev[j];
      else nxt[j-1] += prev[j];
      nxt[j+1] += 2*prev[j];
    }
    rep(j,n+1) nxt[j] %= MOD;
    swap(prev, nxt);
  }

  long ans = prev[m];
  ans *= mod_inv(mod_pow(2,m));

  cout << ans%MOD << endl;

  return 0;
}
