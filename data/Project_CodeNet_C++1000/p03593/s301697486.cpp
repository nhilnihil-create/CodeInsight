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
  int H,W;
  cin >> H >> W;
  vector<string> G(H);
  for(int i=0; i<H; i++){
    cin >> G[i];
  }
  map<char,int> mp;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      mp[G[i][j]]++;
    }
  }
  int cnt_4=0,cnt_2=0,cnt_odd=0;
  for(auto m: mp){
    cnt_4 += m.second/4;
    if(m.second%2){
      cnt_odd++;
    }
  }
  if(cnt_4 >= (H/2)*(W/2)){
    if((H%2 && W%2 && cnt_odd==1) || ((H%2==0 || W%2==0) && cnt_odd==0)){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else{
    cout << "No" << endl;
  }
  return 0;
}
