#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#ifdef ENABLE_DEBUG
#define dump(a) cerr<<#a<<"="<<a<<endl
#define dumparr(a,n) cerr<<#a<<"["<<n<<"]="<<a[n]<<endl
#else
#define dump(a) 
#define dumparr(a,n) 
#endif
#define FOR(i, a, b) for(ll i = a;i < b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(ll i = b-1;i >= a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)
#define SIGN(a) (a==0?0:(a>0?1:-1))

typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<ll,pll> ppll;
typedef vector<ll> vll;

const ll INF=(1LL<<50);
#if __cplusplus<201700L
ll gcd(ll a, ll b) {
  if(a < b) return gcd(b, a);
  ll r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}
#endif

template<class S,class T>
std::ostream& operator<<(std::ostream& os,pair<S,T> a){
  os << "(" << a.first << "," << a.second << ")";
  return os;
}
template<class T>
std::ostream& operator<<(std::ostream& os,vector<T> a){
  os << "[ ";
  REP(a.size()){
    os<< a[i] << " ";
  }
  os<< " ]";
  return os;
}


void solve(long long N, std::vector<long long> a){
  ll l=-1,r=2*N+10;
  while(l+1<r){
    ll mid=(l+r)/2;
    dump(mid);
    vector<int> x(a.size());
    REP(a.size()){
      if(a[i]>=mid){
        x[i]=1;
      }else{
        x[i]=0;
      }
    }
    ll bl=a.size()/2,br=a.size()/2;
    while(bl>0){
      if(x[bl]==x[bl-1]){
        break;
      }
      --bl;
    }
    while(br<x.size()-1){
      if(x[br]==x[br+1]){
        break;
      }
      ++br;
    }
    dump(br);dump(bl);
    ll tmp;
    if(bl==0&&br==x.size()-1){
      tmp=x[0];
    }else if(a.size()/2-bl<br-a.size()/2){
      tmp=x[bl];
    }else{
      tmp=x[br];
    }
    if(tmp==1){
      l=mid;
    }else{
      r=mid;
    }
  }
  cout<<l<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(2*N-1);
    for(int i = 0 ; i < 2*N-1 ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
