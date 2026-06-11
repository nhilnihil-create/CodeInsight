#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  string S;
  cin >> S;
  int i = 0;
  bool bad = true;
  while (bad && i < S.size()) {
    bad = false;
    if (S[i] == 'd') {
      if (i < S.size() && S.substr(i, 5) == "dream") {
        //cout << "dream" <<endl;
        i += 5;
        bad = true;
        if(i < S.size() && S.substr(i, 2) == "er"){
          if(!(S.substr(i, 3) == "era")){
            i+=2;
          }
        }
      }
    } else if (S[i] == 'e') {
      if (i < S.size() && S.substr(i, 5) == "erase") {
        //cout << "erase" <<endl;
        i += 5;
        bad = true;
        if (i < S.size() && S.substr(i, 1) == "r") {
          i += 1;
          //cout << "r" <<endl;
        }
      }
    }
  }
  if(i == S.size()){
    cout << "YES" <<endl;
  } else{
    cout << "NO" <<endl;
  }
}
