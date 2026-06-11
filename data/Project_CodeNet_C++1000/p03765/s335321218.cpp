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

int main(void){
  SPEEDUP
  cout << setprecision(15);
  string s,t;cin >> s >> t;
  vector<int>sa(s.length()+1,0);
  vector<int>sb(s.length()+1,0);
  vector<int>ta(t.length()+1,0);
  vector<int>tb(t.length()+1,0);
  rep(i,s.length()){
    if(s[i]=='A')++sa[i+1];
    else++sb[i+1];
  }
  rep(i,s.length()){
    sa[i+1] += sa[i];
    sb[i+1] += sb[i];
  }
  rep(i,t.length()){
    if(t[i]=='A')++ta[i+1];
    else++tb[i+1];
  }
  rep(i,t.length()){
    ta[i+1] += ta[i];
    tb[i+1] += tb[i];
  }

  int Q;cin >> Q;
  while(Q--){
    int a,b,c,d;cin >> a >> b >> c >> d;
    --a;--c;
    int SA = sa[b]-sa[a]+2*(sb[b]-sb[a]);
    int TA = ta[d]-ta[c]+2*(tb[d]-tb[c]);
    YESNO((SA-TA)%3==0);
  }
  return 0;
}
