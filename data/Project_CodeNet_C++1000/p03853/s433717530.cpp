#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

typedef long long ll;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int h, w; cin >> h >> w;
  vector<string> s(h);  cin >> s;
  vector<string> ans(2*h);
  for (int i = 0; i < 2*h; ++i){
    for (int j = 0; j < w; ++j){
      ans[i] += s[i/2][j];
    }
  }
  for (int i = 0; i < 2*h; ++i){
    cout << ans[i] << "\n";
  }
  return 0;
}