#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,m; cin >> n >> m;
  vector<string> a(n),b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  rep(i,n-m+1){
    rep(j,n-m+1){
      bool ok = true;
      rep(k,m){
        if(a[i+k].substr(j,m) != b[k]) ok = false;
      }
      if(ok){
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
  cout << "\n";
  return 0;
}
