#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;
  char h = s[0];
  char l = s[s.size()-1];
  string x = to_string(s.size()-2);

  string ans ="";
  ans+=h;
  ans+=x;
  ans+=l;

  cout << ans << endl;
  
  return 0;
}
