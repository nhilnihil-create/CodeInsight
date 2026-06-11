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
constexpr ll INF = 9e18;
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

int main(){
  int N,T;
  cin >> N >> T;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  int m = A[0];
  vector<int> vec;
  int max_now=A[0];
  for(int i=1; i<N; i++){
    if(m <= A[i]){
      max_now = A[i];
      vec.push_back(max_now - m);
    }else{
      m = A[i];
    }
  }
  sort(vec.begin(),vec.end(),greater<int>());
  int cnt = 0;
  for(int i=0; i<vec.size(); i++){
    if(vec[0] == vec[i]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
