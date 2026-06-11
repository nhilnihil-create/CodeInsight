#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)
#define ALL(x) (x).begin(),(x).end()
template<class T>bool umax(T &a, const T &b) {if(a<b){a=b;return 1;}return 0;}
template<class T>bool umin(T &a, const T &b) {if(b<a){a=b;return 1;}return 0;}

template<typename A,size_t N,typename T> void FILL(A (&array)[N],const T &val){fill((T*)array,(T*)(array+N),val);}
template<typename T> void FILL(vector<T> &v, const T &x) {fill(v.begin(), v.end(), x);}
template<typename T> void FILL(vector<vector<T>> &v, const T &x) {for(auto &i:v)fill(i.begin(), i.end(), x);}

// https://atcoder.jp/contests/abc074/tasks/arc083_a
bool dp[3001][3001];
int main() {
  int a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;

  auto check = [&] (int water, int sugar) {
    return water * e >= sugar * 100;
  };

  int ans_sugar = 0;
  int ans_water = 0;
  
  dp[0][0] = true;
  rep(i, f+1) rep(j, f+1) {
    if(!dp[i][j]) continue;
    if(i+100*a+j <=f) dp[i+100*a][j] = dp[i][j];
    if(i+100*b+j <=f) dp[i+100*b][j] = dp[i][j];
    if(i+j+c <=f && check(i, j+c)) dp[i][j+c] = dp[i][j];
    if(i+j+d <=f && check(i, j+d)) dp[i][j+d] = dp[i][j];
    
    // (100 * ans_sugar) / (ans_sugar + ans_water) < (100 * j) / (i+j)
    if((ans_sugar ==0) ||  (100 * ans_sugar) * (i+j) < (100 * j) * (ans_sugar + ans_water)) {
      ans_sugar = j;
      ans_water = i;
    }
  }
  cout << (ans_sugar+ans_water) << " " << ans_sugar <<endl;
}
