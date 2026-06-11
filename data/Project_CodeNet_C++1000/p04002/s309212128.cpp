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
  ll H,W,N;
  cin >> H >> W >> N;
  vector<P> p;
  for(int i=0; i<N; i++){
    int a,b;
    cin >> a >> b;
    for(int j=0; j<3; j++){
      for(int k=0; k<3; k++){
        int na = a-j;
        int nb = b-k;
        if(na<=0 || nb<=0 || H<na+2 || W<nb+2) continue;
        p.emplace_back(na,nb);
      }
    }
  }
  sort(p.begin(),p.end());
  vector<ll> sum(10,0);
  for(int i=0; i<p.size(); i++){
    int cnt=1;
    while(i+1<p.size() && p[i].first == p[i+1].first && p[i].second == p[i+1].second){
      cnt++;
      i++;
    }
    sum[cnt]++;
  }
  ll s=0;
  for(int i=1; i<=9; i++){
    s += sum[i];
  }
  sum[0] = (H-2)*(W-2) - s;
  for(int i=0; i<10; i++){
    cout << sum[i] << endl;
  }
  return 0;
}
