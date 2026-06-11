#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;

int main() {
  string S, T="";
  cin >> S;
  for (char c:S) {
    if (c=='B') {
      if (T.size()==0) {continue;}
      else {T.erase(T.size()-1);}
    }
    else {T.push_back(c);}
  }
  cout << T << endl;
}