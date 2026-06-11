//問題やり直し
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string T[4] = {"maerd", "remaerd", "esare", "resare"};

int main(void)
{
  string S;
  cin >> S;
  reverse(S.begin(),S.end());
  // cout << S << endl;

  while(S.length() != 0){
    for(int i=0; i<4; i++){
    if(S.compare(0,T[i].length(),T[i]) == 0){
      S.erase(0,T[i].length());
      break;
    }
    if(i==3){
      cout << "NO\n";
      return 0;
    }
  }
}
  cout << "YES\n";
  return 0;
}
