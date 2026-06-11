#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  string s;
  cin >> s;
  for(int i = 97; i <= 122; i++){
    char x = i;
    bool flag = true;
    rep(j,s.size()){
      if(x == s.at(j)) flag = false;
    }
    if(flag){
      cout << x << endl;
      return 0;
    }
  }
  cout << "None" << endl;
 }
