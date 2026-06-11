#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const int INF = 1001001001;
int main(){
  string s;
  cin >> s;
  int n = s.length();
  int a = INF, b = INF;
  if (s.length() == 2) {
    if(s[0] == s[1]) cout << 1 << ' ' << 2 << endl;
    else cout << -1 << ' ' << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n - 2; ++i) {
    string t = s.substr(i, 3);
    if(t[0] == t[1] || t[0] == t[2] || t[1] == t[2]) {
      a = i;
      b = i + 2;
    }
  }
  if(a != INF) cout << a + 1 << ' ' << b + 1 << endl;
  else cout << -1 << ' ' << -1 << endl;
}