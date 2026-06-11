#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e9
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n,c,k; cin >> n >> c >> k;
  vi t(n); rep(i,n) cin >> t[i];

  int ans = 0, cnt = 0, j = 0;
  sort(all(t));
  rep(i,n){
    if(c == cnt || t[j]+k < t[i]){
      cnt = 0;
      j = i;
      ans++;
    }
    cnt++;
  }
  cout << ans+1;
  cout << "\n";
  return 0;
}
