#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int INF = 1e9;
const int MOD = 1000000007;

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  
  rep(i,n+1){
    rep(j,m+1){
      int x=i;
      int y=j;
      if(m*x+n*y-2*x*y==k){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No"<< endl;
  
  
}