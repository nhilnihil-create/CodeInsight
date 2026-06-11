#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  string S; cin >> S;
  
  string T;
  int k = 0, t = 0;
  rep(i, N) {
    if(S[i] == '(') k++;
    else k--;
    if(k < 0) {
      t++;
      k++;
    } 
  }
  
  rep(i, t) cout << '(';
  cout << S;
  rep(i, k) cout << ')';
  cout << endl;


}