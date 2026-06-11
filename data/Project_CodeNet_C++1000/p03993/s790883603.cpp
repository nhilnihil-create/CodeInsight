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
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  int n;
  cin >> n;
  vbool judge(n,true);
  vint a(n);
  rep(i,n){
    cin >> a[i];
    a[i]--;
  }
  int ans = 0;
  rep(i,n){
    if(judge[a[i]] && a[a[i]] == i){
      ans++;
      judge[i] = false;
      judge[a[i]] = false;
    }
  }
  cout << ans << endl;
}