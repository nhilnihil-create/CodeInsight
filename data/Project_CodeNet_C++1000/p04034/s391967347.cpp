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
  vi cnt(n,1);
  set<int> st = {0};
  rep(i,m){
    int x,y; cin >> x >> y;
    x--; y--;
    if(st.count(x)) st.insert(y);
    cnt[x]--; cnt[y]++;
    if(cnt[x] == 0) st.erase(x);
  }
  cout << st.size();
  cout << "\n";
  return 0;
}
