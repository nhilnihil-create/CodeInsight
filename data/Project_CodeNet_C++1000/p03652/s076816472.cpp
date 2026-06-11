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
  int N,M;cin >> N >> M;
  vector<vector<int> > v(N,vector<int> (M));
  rep(i,N)rep(j,M){
    cin >> v[i][j];
    --v[i][j];
  }
  //参加人数がX人以下となるようにできるか．
  auto f = [&](int X){
    //j番目のスポーツのプレイ人数
    vector<int> w(M);
    vector<bool> open(M,true);
    while(true){
      rep(i,M)w[i] = 0;
      rep(i,N){
        int play = M+1;
        rep(j,M){
          if(!open[v[i][j]])continue;
          play = v[i][j];
          break;
        }
        if(play == M+1) return false;
        ++w[play];
      }
      bool sat = true;
      rep(j,M) if(w[j] > X){
        sat = false;
        open[j] = false;
      }
      if(sat)return true;
    }
    return false;
  };
  int l = 0, r = N;
  while(r-l>1){
    int m = (l+r)/2;
    if(f(m))r = m;
    else l = m;
  }
  cout << r << endl;
  return 0;
}
