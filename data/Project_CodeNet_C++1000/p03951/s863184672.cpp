#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 100000000000000009
#define MOD 1000000007
#define int long long
using P = pair<int,int>;
signed main(){
  int n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  int count = 0;
  int ans = 2*n;
  for(int i = n;i > 0;i--){
    if(s.substr(n-i,i) == t.substr(0,i)){
      ans = 2*n-i;
      break;
    }
  }
  cout << ans << endl;
}