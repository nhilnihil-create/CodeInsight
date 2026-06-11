#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)

int main(){
  string S;
  cin >> S;

  vector<string> Strings={"dream", "dreamer", "erase", "eraser"};

  reverse(S.begin(), S.end());
  rep(i, 4){
    string &tmp = Strings.at(i);
    reverse(tmp.begin(), tmp.end());
  }

  bool can = true;
  for(int i = 0; i < (int)S.size();){
    bool can2 = false;
    for(string d : Strings){
      if(S.substr(i, d.size()) == d){
        can2 = true;
        i += d.size();
        break;
      }
    }
    if (!can2){
      can = false;
      break;
    }
  }

  if(can) cout << "YES" << endl;
  else cout << "NO" << endl;

}
