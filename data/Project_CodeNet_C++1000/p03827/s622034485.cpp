#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

typedef long long ll;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int n;  cin >> n;
  string s; cin >> s;
  int now = 0, ans = 0;
  for (int i = 0; i < s.size(); ++i){
    if(s[i]=='I') now++;
    else if(s[i]=='D')  now--;
    ans = max(ans, now);
  }
  cout << ans << "\n";
  return 0;
}