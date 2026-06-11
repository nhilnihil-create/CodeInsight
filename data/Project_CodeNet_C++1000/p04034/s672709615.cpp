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
  int n,m; cin >> n >> m;
  vi x(m),y(m);
  rep(i,m){
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }

  vi cnt(n,1);
  set<int> st = {0};
  rep(i,m){
    if(st.count(x[i])) st.insert(y[i]);
    cnt[x[i]]--; cnt[y[i]]++;
    if(cnt[x[i]] == 0) st.erase(x[i]);
  }
  cout << st.size();
  cout << "\n";
  return 0;
}
