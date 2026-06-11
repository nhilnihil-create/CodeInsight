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
  vint A(n);
  bool judge = false;
  rep(i,n) cin >> A[i];
  int ans = 0;
  rep(i,n){
    if(A[i] % 2 == 1 && judge){
      ans++;
      judge = false;
    }
    else if(A[i] % 2 == 1) judge = true;
    if(A[i] == 0) judge = false; 
    ans += A[i]/2;
    //cout << ans << endl;
  }
  cout << ans << endl;
}