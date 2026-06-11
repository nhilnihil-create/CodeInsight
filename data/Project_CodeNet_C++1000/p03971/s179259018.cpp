#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define _GLIBCXX_DEBUG
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
const ll INF = 9223372036854775807;

int main() {
  int n,a,b;cin >> n >> a >> b;
  string s;cin >> s;
  vector<string> Ans(n,"No");
  int counta = 0;
  int countb = 0;
  rep(i,n) {
    if(s[i] == 'a'&&counta < a+b) {
      Ans[i] = "Yes";
      counta++;
    }
    else if(s[i] == 'b'&&counta < a+b) {
      if(countb < b) {
        Ans[i] = "Yes";
        counta++;
        countb++;
      }
    }
  }
  rep(i,n) cout << Ans[i] << endl;
}