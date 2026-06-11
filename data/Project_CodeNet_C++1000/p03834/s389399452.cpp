#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;

  rep(i,5) cout << s[i];
  cout << " ";
  for(int i = 6;i<=12;i++) cout << s[i];
  cout << " ";
  for(int i = 14;i<s.size();i++) cout << s[i];
    
  return 0;
}
