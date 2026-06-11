#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  cin >> S;

  set<char> c;

  for (int i = 0; i < S.size(); i++)
  {
    if (c.count(S.at(i))){
      cout << "no" << endl;
      return 0;
    }
    else{
      c.insert(S.at(i));
    }
  }
  cout << "yes" << endl;
}