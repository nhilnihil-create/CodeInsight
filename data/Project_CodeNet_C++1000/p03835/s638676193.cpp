#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int k,s; cin >> k >> s;
  int ans = 0;
  rep(i,k+1){
    rep(j,k+1){
      if(0 <= s-i-j && s-i-j <= k) ans++;
    }
  }
  cout << ans;
  cout << "\n";
  return 0;
}
