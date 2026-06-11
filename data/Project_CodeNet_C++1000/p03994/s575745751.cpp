#include<bits/stdc++.h>
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
  string S;
  cin >> S;
  int K;
  cin >> K;
  for(int i=0; i<S.size(); i++){
    if(S[i] == 'a') continue;
    int diff = 26 - (S[i] - 'a');
    if(diff <= K){
      K -= diff;
      S[i] = 'a';
    }
  }
  S[S.size()-1] = ((S[S.size()-1] - 'a') + K)%26 + 'a';
  cout << S << endl;
  return 0;
}
