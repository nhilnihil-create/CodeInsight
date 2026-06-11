#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n,m,k; cin >> n >> m >> k;
  bool ok = false;
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
      if(k == n*j + m*i - i*j*2) ok = true;
    }
  }
  if(ok) cout << "Yes";
  else cout << "No";
  cout << "\n";
  return 0;
}
