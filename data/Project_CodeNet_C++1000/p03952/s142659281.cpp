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
  int N,x;
  cin >> N >> x;
  if(x == N*2-1 || x == 1){
    cout << "No" << endl;
    return 0;
  }
  if(N == 2){
    cout << "Yes" << endl;
    for(int i=1; i<=3; i++){
      cout << i << endl;
    }
    return 0;
  }
  cout << "Yes" << endl;
  if(x == 2){
    set<int> se;
    se.insert(x+1);
    se.insert(x);
    se.insert(x-1);
    se.insert(x+2);
    int k=1;
    for(int i=1; i<=N*2-1; i++){
      if(i == N-1){
        cout << x-1 << endl;
      }else if(i == N){
        cout << x << endl;
      }else if(i == N+1){
        cout << x+1 << endl;
      }else if(i == N+2){
        cout << x+2 << endl;
      }else{
        if(se.count(k)){
          while(se.count(k)){
            k++;
          }
        }
        cout << k << endl;
        k++;
      }
    }
  }else{
    set<int> se;
    se.insert(x-1);
    se.insert(x);
    se.insert(x+1);
    se.insert(x-2);
    int k=1;
    for(int i=1; i<=2*N-1; i++){
      if(i == N-1){
        cout << x+1 << endl;
      }else if(i == N){
        cout << x << endl;
      }else if(i == N+1){
        cout << x-1 << endl;
      }else if(i == N+2){
        cout << x-2 << endl;
      }else{
        if(se.count(k)){
          while(se.count(k)){
            k++;
          }
        }
        cout << k << endl;
        k++;
      }
    }
  }
  return 0;
}
