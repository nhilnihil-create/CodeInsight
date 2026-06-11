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
  int N;cin >> N;
  vector<ll> v(3*N);
  vector<ll> pre(N+1);
  vector<ll> suf(N+1);
  priority_queue<ll, vector<ll>, greater<ll> > preq;
  priority_queue<ll> sufq;
  ll sum1 = 0;
  ll sum2 = 0;
  rep(i,3*N){
    cin >> v[i];
    if(i<N){
      sum1+=v[i];
      preq.push(v[i]);
    }
    if(i>=2*N){
      sum2+=v[i];
      sufq.push(v[i]);
    }
  }
  pre[0] = sum1;
  rep(i,N){
    pre[i+1] = pre[i];
    if(v[i+N] > preq.top()){
      pre[i+1] += v[i+N] - preq.top();
      preq.pop();
      preq.push(v[i+N]);
    }
  }
  suf[N] = sum2;
  per(i,N){
    suf[i] = suf[i+1];
    if(v[i+N] < sufq.top()){
      suf[i] += v[i+N] - sufq.top();
      sufq.pop();
      sufq.push(v[i+N]);
    }
  }

  ll maximum;
  rep(i,N+1){
    //cout << pre[i] SP suf[i] << endl;
    if(i==0) maximum = pre[i] - suf[i];
    else maximum = max(maximum, pre[i] - suf[i]);
  }
  cout << maximum << endl;
  return 0;
}
