#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0,i##_max=(N);i<i##_max;++i)
#define repp(i,l,r) for(int i=(l),i##_max=(r);i<i##_max;++i)
#define per(i,N) for(int i=(N)-1;i>=0;--i)
#define perr(i,l,r) for(int i=r-1,i##_min(l);i>=i##_min;--i)
#define all(arr) (arr).begin(), (arr).end()
#define SP << " " <<
#define SPF << " "
#define SPEEDUP cin.tie(0);ios::sync_with_stdio(false);
#define MAX_I INT_MAX //1e9
#define MIN_I INT_MIN //-1e9
#define MAX_UI UINT_MAX //1e9
#define MAX_LL LLONG_MAX //1e18
#define MIN_LL LLONG_MIN //-1e18
#define MAX_ULL ULLONG_MAX //1e19
  typedef long long ll;
  typedef pair<int,int> PII;
  typedef pair<char,char> PCC;
  typedef pair<ll,ll> PLL;
  typedef pair<char,int> PCI;
  typedef pair<int,char> PIC;
  typedef pair<ll,int> PLI;
  typedef pair<int,ll> PIL; 
  typedef pair<ll,char> PLC; 
  typedef pair<char,ll> PCL; 

inline void YesNo(bool b){ cout << (b?"Yes" : "No") << endl;}
inline void YESNO(bool b){ cout << (b?"YES" : "NO") << endl;}
inline void Yay(bool b){ cout << (b?"Yay!" : ":(") << endl;}

const int N_MAX = 5010;
int N,K;
ll v[N_MAX];

//v[index]を使わずにk-v[index]<= Sum < kとなる挿話が作れるならfalse
bool isNoNeed(int index){
  //i枚目まで使った時にjにできるか
  //trueできる，falseできない
  bool dp[2][K];
  bool *prev, *next;
  prev = dp[0];
  next = dp[1];
  rep(j,K){
    prev[j] = false;
    next[j] = false;
  }
  prev[0] = true;

  rep(i,N){
    if(i==index)continue;
    rep(j,K){
      next[j] = (prev[j]||next[j]);
      if(prev[j]){
        if(j+v[i]<K-v[index]) next[j+v[i]] = true;
        else if(j+v[i] < K) return false;
        else break;
      }
    }
    swap(prev,next);
  }
  return true;
}

int main(void){
  SPEEDUP
  cout << setprecision(15);
  int n;cin >> n >> K;
  N=0;
  rep(i,n){
    int x;cin >> x;
    if(x>=K)continue;
    else v[N++]=x;
  }
  sort(v,v+N);
  int l = 0, r=N;
  if(!isNoNeed(l)){
    cout << 0 << endl;
    return 0;
  }
  while(r-l>1){
    int m = (r+l)/2;
    bool isnoneed = isNoNeed(m);
    if(isnoneed) l = m;
    else r = m;
  }
  cout << r << endl;
  return 0;
}

