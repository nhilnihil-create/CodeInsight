#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<assert.h>
#include<string>
#include<cstdlib>
#include<cctype>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<stack>
// #include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 1LL<<60;
constexpr int inf = 1e9;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};

// intやllをstringに変換
template<typename T> inline string toString(const T &a){
  ostringstream oss;
  oss << a;
  return oss.str();
};
// ----------------------------------------------------------------------------

int dp[50][500][500];
int main(){
  int N,Ma,Mb;
  cin >> N >> Ma >> Mb;
  for(int i=0; i<50; i++){
    for(int j=0; j<500; j++){
      for(int k=0; k<500; k++){
        dp[i][j][k] = inf;
      }
    }
  }
  dp[0][0][0] = 0;
  for(int i=0; i<N; i++){
    int A,B,C;
    cin >> A >> B >> C;
    for(int a=0; a<500; a++){
      for(int b=0; b<500; b++){
        if(dp[i][a][b] == inf) continue;
        chmin(dp[i+1][a][b],dp[i][a][b]);
        chmin(dp[i+1][a+A][b+B],dp[i][a][b] + C);
      }
    }
  }
  int ans = inf;
  for(int a=1; a<500; a++){
    for(int b=1; b<500; b++){
      if(Mb*a == Ma*b){
        chmin(ans,dp[N][a][b]);
      }
    }
  }
  if(ans == inf){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
  return 0;
}
