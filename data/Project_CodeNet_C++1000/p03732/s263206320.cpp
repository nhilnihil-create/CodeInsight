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

const int V_MAX = 1e7+3;

int main(void){
  SPEEDUP
  cout << setprecision(15);
  int N;cin >> N;
  ll W;cin >> W;
  int M = 4;
  vector<vector<ll> > item(M);
  ll weight = 0;
  rep(i,N){
    ll w,v;cin >> w >> v;
    if(i==0) weight = w;
    int num = w-weight;
    item[num].push_back(v);
  }
  rep(i,M) sort(all(item[i]),greater<ll>());
  map<ll,ll> mp;
  mp[0] = 0;
  rep(i,M){
    for(ll &v : item[i]){
      for(auto itr = mp.rbegin(), mp_rend = mp.rend();itr != mp_rend; ++itr){
        ll pw = itr->first;
        ll pv = itr->second;
        ll nw = pw + weight + i;
        if(nw <= W){
          if(mp.count(nw))mp[nw] = max(mp[nw], pv+v);
          else mp[nw] = pv+v;
        }
      }
    }
  }
  ll maximum = 0;
  for(auto itr = mp.begin(), mp_end = mp.end();itr != mp_end; ++itr) maximum = max(maximum,itr->second);

  cout << maximum << endl;
  return 0;
}
