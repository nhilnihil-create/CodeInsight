#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  string s;
  int cnt = 0;
  cin >> s;
  rep(i,1,s.size()) if(s[i] != s[i-1]) cnt++;
  cout << cnt << endl;
}