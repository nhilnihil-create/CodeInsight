#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD =1e9+7;
using ll=long long;
int n, cnt;
string s, t;
int main(){
  cin >> n >> s >> t;
  for(int i = 1; i <= min(s.size(), t.size()); i++){
    string sa = s.substr(s.size() - i, i);
    string ta = t.substr(0, i);
    if(sa == ta) cnt = i;
  }
  if(s == t) cout << s.size() << endl;
  else cout << s.size() + t.size() - cnt << endl; 
}
