#include<bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define REP(i, n) for(int i = 0;i < (n);++i)
#define RREP(i, n) for(int i = (n)-1; i >= 0; --i)

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define pque priority_queue
#define umap unordered_map
#define BIG 2000000000
#define VERYBIG 1000000000000000ll
#define PI 3.14159265358979
#define coutdb cout<<fixed<<setprecision(30)

const int dx[]={1,0,-1,0,1,1,-1,-1}, dy[]={0,-1,0,1,1,-1,1,-1};
const long long MOD = 1e9+7;

// typedef int_fast64_t ll;
#define int int_fast64_t

template<typename T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template<typename T> inline T LCM(T a,T b){T c=GCD(a,b);a/=c;return a*b;}
template<typename T> inline T nCr(T a,T b){T i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
template<typename T> inline T nHr(T a,T b){return nCr(a+b-1,b);}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}

typedef pair<int, int> INTP;
typedef vector<int> INTV;
struct edge2 {int to, cost;};
struct edge3 {int from, to, cost;};

signed main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M, A[100000]; cin >> N >> M;
  REP(i, N) cin >> A[i];
  int imos[200010] = {};
  REP(i, N-1){
    if(A[i] < A[i+1]){
      imos[A[i]+1]++; imos[A[i+1]]--;
    } else {
      imos[A[i]+1]++; imos[A[i+1]+M]--;
    }
  }
  REP(i, 2*M+1) imos[i+1] += imos[i];
  umap<int, int> mp;
  int cnt = 0;
  REP(i, N-1){
    mp[A[i+1]] += (A[i+1]+M-A[i]) % M - 1;
    if(A[i] < A[i+1]) cnt += A[i+1]-A[i];
    else cnt += 1 + A[i+1]-1;
  }
  // cerr << cnt << endl;
  int ans = cnt;
  for(int x = 1; x < M; x++){
    cnt -= imos[x]+imos[x+M];
    cnt += mp[x];
    // cerr << cnt << endl;
    chmin(ans, cnt);
  }
  cout << ans << endl;
}