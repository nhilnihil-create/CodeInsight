#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

 
int main() {
  int n,t;
  cin >> n >> t;
  vector<int> a(n);
  rep(i,n) cin >> a.at(i);
  ll ans = 0;
  rep(i,n){
    if(i== n-1) ans += t;
    else{
      ans += min(a.at(i+1) - a.at(i),t);
    }
  }
  
  cout << ans << endl;
  return 0;
}

