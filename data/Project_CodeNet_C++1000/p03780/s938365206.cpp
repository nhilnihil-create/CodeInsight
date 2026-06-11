#include <bits/stdc++.h>
#define FOR(v, a, b) for(int v = (a); v < (b); ++v)
#define FORE(v, a, b) for(int v = (a); v <= (b); ++v)
#define REP(v, n) FOR(v, 0, n)
#define REPE(v, n) FORE(v, 0, n)
#define REV(v, a, b) for(int v = (a); v >= (b); --v)
#define RS resize
#define CLR clear
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define LLI long long int
using namespace std;

template <typename T> using V = vector<T>;
template <typename T, typename U> using P = pair<T,U>;

template <typename T> T gcd(T a, T b){a = abs(a); b = abs(b); if(a<b) swap(a,b); while(b>0){a %= b; swap(a,b);} return a;}
template <typename T> T lcm(T a, T b){return (1LL * a * b) / gcd(a,b);}

int N,K;
vector<int> a;

bool dpL[5001][5001];
bool dpR[5001][5001];

bool judge(int x){
  if(a[x] >= K) return true;

  //cout << "a[" << x << "] = " << a[x] << endl;
  //cout << x-1 << " " << N-x-1 << endl;
  bool r = false;
  FOR(i,K-a[x],K){
    REPE(j,i){
      if(dpL[x][j] && dpR[N-x-1][i-j]){
	//cout << j << " " << i-j << endl;
	r = true; break;
      }
    }
    if(r) break;
  }
  return r;
}

int binary_search(int lower, int upper){
  //cout << lower << "," << upper << endl;
  if(lower == upper) return lower;
  if(lower+1 == upper){
    bool l = judge(lower), u = judge(upper);
    if(l && u) return lower;
    if((!l) && (!u)) return N;
    return upper;
  }
  int mid = (lower+upper)/2;

  if(judge(mid))
    binary_search(lower, mid);
  else
    binary_search(mid, upper);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> K;
  a.resize(N);
  REP(i,N) cin >> a[i];
  sort(ALL(a));  

  REPE(i,5000) REPE(j,5000) dpL[i][j] = (j==0);  
  FORE(i,1,N)
    FORE(j,1,K)
      if(j < a[i-1]) dpL[i][j] = dpL[i-1][j];
      else dpL[i][j] = dpL[i-1][j] || dpL[i-1][j-a[i-1]];

  REPE(i,5000) REPE(j,5000) dpR[i][j] = (j==0);  
  FORE(i,1,N)
    FORE(j,1,K)
      if(j < a[N-i]) dpR[i][j] = dpR[i-1][j];
      else dpR[i][j] = dpR[i-1][j] || dpR[i-1][j-a[N-i]];
  /*
  REPE(i,N){
    REPE(j,K) cout << dpL[i][j] << " ";
    cout << endl;
  }
  cout << endl;
  REPE(i,N){
    REPE(j,K) cout << dpR[i][j] << " ";
    cout << endl;
    }*/

  
  //REP(i,N) cout << a[i] << " "; cout << endl;
  //REP(i,N) cout << judge(i) << " "; cout << endl;
  
  cout << binary_search(0, N-1) << endl;
  
  return 0;
}
