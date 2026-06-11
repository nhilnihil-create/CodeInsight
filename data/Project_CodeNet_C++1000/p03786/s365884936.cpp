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
  rep(i,n) cin >> A[i];
  sort(A.begin(),A.end());
  vint SUM(n);
  int sum = 0;
  rep(i,n){
    sum += A[i];
    SUM[i] = sum;
  }
  int ans = 1;
  for(int i = n-2;i >= 0;i--){
    if(SUM[i]*2 >= A[i+1]) ans++;
    else break;
  }
  cout << ans << endl;
}