#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip> // setprecision
#include <complex> // complex
#include <math.h> 
#include <climits> 
#include <assert.h>
#include <random>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr ll mod = 1'000'000'007;
constexpr ll mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[8] = {1, 0, -1, 0,1,1,-1,-1};
const int dy[8] = {0, 1, 0, -1,1,-1,1,-1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ---------------------------------------------------------------------------

int main(){
  int N,x;
  cin >> N >> x;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  reverse(A.begin(),A.end());
  vector<vector<int>> G(N,vector<int>(N,inf+10));
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(j){
        chmin(G[i][j],G[i][j-1]);
      }
      chmin(G[i][j],A[(i+j)%N]);
    }
  }
  ll ans = INF;
  for(int i=0; i<N; i++){
    ll now = 0;
    for(int j=0; j<N; j++){
      now += G[j][i];
    }
    now += (ll)x*i;
    chmin(ans,now);
  }
  cout << ans << "\n";
  return 0;
}