#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  string s;
  cin >> s;

  int bi;
  rep(i,s.size()){
    if (s[i] == 'A'){
      bi = i;
      break;
    }
  }
  int ei;
  rep(i,s.size()){
    if (s[s.size() - 1 - i] == 'Z'){
      ei = s.size() - 1 - i;
      break;
    }
  }
  cout << ei - bi + 1 << endl;
  return 0;
}