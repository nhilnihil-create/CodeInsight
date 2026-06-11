#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  cin >> S;

  set<char> alpha;

  for (int i = 0; i < S.size(); i++){
    alpha.insert(S.at(i));
  }

  for (char i = 'a'; i <= 'z'; i++)
  {
    if (!alpha.count(i)){
      cout << i << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}