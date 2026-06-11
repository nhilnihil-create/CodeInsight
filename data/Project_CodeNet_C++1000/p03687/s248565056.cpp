#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  string s;
  cin >> s;
  int ans = INF;

  rep(cc, 26) {
    string st = s;
    char c = 'a' + cc;
    int cnt = 0;

    while(1) {
      // cout << st << endl;
      bool ok = true;
    
      rep(i, st.length()) {
        if (st[i] != c) ok = false;
      }
      if (ok) break;
      string t;
      rep(i, st.length() - 1) {
        if (st[i] == c || st[i + 1] == c) t.push_back(c);
        else t.push_back(st[i]);
      }
      st = t;
      cnt++;
    }
    chmin(ans, cnt);
  }

  cout << ans << endl;

}