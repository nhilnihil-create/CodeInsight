#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;
  bool in = false;
  rep(i,s.size())
    if(s[i]=='9')
      in = true;

  if(in) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
