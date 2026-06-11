#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;

  bool dup = false;
  for(int i = 0;i<s.size();i++)
    for(int j = i+1;j<s.size();j++)
      if(s[i]==s[j]) dup = true;

  if(!dup) cout << "yes" << endl;
  else cout << "no" << endl;
  
  return 0;
}
