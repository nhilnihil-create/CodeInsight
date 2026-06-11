#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++)
  {
    if (i % 2 == 0){
      cout << s.at(i) ;
    }
  }
  cout << "" << endl;
}