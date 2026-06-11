#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  int n, m;
  cin >> n >> m;
  vector<int> posx(n);
  vector<int> posy(n);
  vector<int> cx(m);
  vector<int> cy(m);
  REP(i,n) {
    int a, b;
    cin >> a >> b;
    posx[i] = a;
    posy[i] = b;
  }

  REP(i,m){
    int a, b;
    cin >> a >> b;
    cx[i] = a;
    cy[i] = b;
  }

  vector<int> ans(n); //check point


  REP(j,n){
    int minlen = 1000000009;
   REP(i,m){
      int sum = 0;
      sum = abs(posx[j]-cx[i]) + abs(posy[j]-cy[i]);
      // cout << minlen << endl;
      // cout << sum << endl;
      if(sum < minlen){
        ans[j] = i + 1;
        minlen = sum;
      }
    }
  }
  for(auto x: ans) cout << x << endl;


  return 0;
}
