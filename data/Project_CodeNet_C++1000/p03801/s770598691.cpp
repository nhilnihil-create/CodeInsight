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

typedef struct{
  //石の数
  ll num;
  //同じ石の数の中で先頭の位置
  int lead;
  //同じ石の数の山の個数
  ll nums;
}T;

bool operator< (const T& l, const T& r){
  return l.num<r.num;
}

int main(void){
  SPEEDUP
  cout << setprecision(15);
  int N;cin >> N;
  vector<ll> v(N,0);
  map<ll,PIL> mp;
  rep(i,N){
    ll x;cin >> x;
    if(mp.count(x)){
      ++mp[x].second;
    }else{
      mp[x] = PII(i,1ll);
    }
  }
  priority_queue<T> pque;
  for(const pair<ll, PII> p : mp){
    pque.push({p.first, p.second.first, p.second.second});
  }
  pque.push({0,-1,0});

  while(!pque.empty()){
    T t = pque.top(); pque.pop();
    T nt = pque.top(); pque.pop();
    v[t.lead] += (t.num - nt.num)*t.nums;
    nt.nums += t.nums;
    nt.lead = min(nt.lead,t.lead);
    if(nt.lead!=-1) pque.push(nt);
  }
  rep(i,N)cout << v[i] << endl;
  return 0;
}
