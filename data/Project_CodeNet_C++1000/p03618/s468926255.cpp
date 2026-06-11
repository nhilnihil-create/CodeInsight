#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  string s;
  cin >> s;
  int n = s.size();
  vint eng(26);
  rep(i,0,n){
    eng[s[i] - 'a']++;
  }
  int ans = n*(n-1)/2 + 1;
  if(n == 1) cout << 1 << endl;
  else{
    rep(i,0,26){
      if(eng[i] >= 2){
        ans -= eng[i]*(eng[i]-1)/2;
      }
    }
    cout << ans << endl;
  }
}