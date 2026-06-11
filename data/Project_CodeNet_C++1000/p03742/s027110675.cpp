#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
  
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

const int mod = 1e9 + 7;

int main() {
  // 考察1. 最終状態を考える
  // 最終状態は 1, 0 か 0, 1のいずれか
  // 考察2. 最終状態になるように石をとる
  // 常に相手の番で|X - Y| <= 1となるようにできれば勝ち
  // 相手はどうあがいても|X - Y| <= 1 の状態からは |X - Y| > 1の状態へにしか変化させられない
  // 自分は|X - Y| > 1 であれば |X - Y| <= 1 にするような手を打つことができる

  ll X, Y;
  cin >> X >> Y;
  cout << (abs(X - Y) > 1 ? "Alice" : "Brown") << endl; 
  return 0;
}