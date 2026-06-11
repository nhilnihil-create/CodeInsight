#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define rep(i,n) for(int i=0;i<n;i++)
const long long MOD = 1000000007;
typedef pair<int,int> P;
typedef long long ll;
ll n,m,k,ans;
string s;

int main(){
  long long a,b;
  cin >> n >> a >> b;
  int x[n]; rep(i,n) cin >> x[i];
  ans = 0;
  rep(i,n-1){
    int tmp = x[i+1]-x[i];
    ans += min(a*tmp, b);
  }
  cout << ans << "\n";
}