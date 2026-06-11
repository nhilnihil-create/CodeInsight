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

const int VMAX =1e5+10;
vector<vector<int> >G(VMAX);

int dfs(int v, int p){
  int ret = 0;
  for(const int& u:G[v]){
    if(u==p)continue;
    ret ^= dfs(u,v)+1;
  }
  return ret;
}

int main(void){
  SPEEDUP
  cout << setprecision(15);
  int V;cin >> V;
  rep(i,V-1){
    int x,y;cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  if(dfs(1,-1))cout << "Alice" << endl;
  else cout << "Bob" << endl;
  return 0;
}
