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

ll C[100][100];

void comb_table(int N){
  for(int i=0; i<N; i++){
    for(int j=0; j<=i; j++){
      if(j==0 || j==1){
        C[i][j] = 1LL;
      }else{
        C[i][j] = C[i-1][j-1]+C[i-1][j];
      }
    }
  }
}

int main(){
  int N,A,B;
  cin >> N >> A >> B;
  vector<ll> v(N);
  map<ll,ll> mp;
  for(int i=0; i<N; i++){
    cin >> v[i];
    mp[v[i]]++;
  }
  comb_table(60);
  sort(v.begin(),v.end(),greater<ll>());
  double max_average = 0;
  for(int i=0; i<A; i++){
    max_average += v[i];
  }
  max_average /= A;
  ll ans = 0;
  int cnt = 0;
  if(mp[v[0]]>A){
    for(int i=A; i<=min((ll)B,mp[v[0]]); i++){
      ans += C[mp[v[0]]+1][i+1];
    }
  }else{
    for(int i=0; i<A; i++){
      if(v[A-1]==v[i]) cnt++;
    }
    ans = C[mp[v[A-1]]+1][cnt+1];
  }
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     cout << "check:" << i << " " << j << " ";
  //     cout << C[i][j] << endl;
  //   }
  // }
  cout << fixed << setprecision(10) << max_average << endl;
  cout << ans << endl;
  return 0;
}
