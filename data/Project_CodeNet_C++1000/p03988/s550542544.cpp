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
  int N;
  cin >> N;
  vector<int> cnt(N,0);
  int mx = 0;
  for(int i=0; i<N; i++){
    int a;
    cin >> a;
    cnt[a]++;
    chmax(mx,a);
  }
  bool can = true;
  if(mx%2){
    if(cnt[(mx+1)/2] != 2) can = false;
    for(int i=(mx+1)/2+1; i<=mx; i++){
      if(cnt[i] < 2) can = false;
    }
  }else{
    if(cnt[mx/2] != 1) can = false;
    for(int i=mx/2+1; i<=mx; i++){
      if(cnt[i] < 2) can = false;
    }
  }
  if(can){
    cout << "Possible\n";
  }else{
    cout << "Impossible\n";
  }
  return 0;
}