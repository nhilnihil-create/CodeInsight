#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  vector<string> ans(n);
  int A = 0;
  int B = 0;
  rep(i, n) {
    if(s.at(i) == 'a'){
      if(A + B < a + b) {
        ans[i] = "Yes";
        A++;
      }
      else ans[i] = "No";
    }  
    if(s.at(i) == 'b'){
      if(A + B < a + b && B < b) {
        ans[i] = "Yes";
        B++;
      }
      else ans[i] = "No";
    }
    if(s.at(i) == 'c') ans[i] = "No";
  }
  rep(i,n) {
    cout << ans[i] << endl;
  }
}