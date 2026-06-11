#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  cin >> S;

  string subS;
  string leftS, rightS;
  int maxLength = 1;

  for (int i = 1; i < S.size() - 1; i++)
  {
    subS = S;
    for (int j = 0; j < i; j++)
    {
      subS.erase(subS.end() - 1);
    }
    
    if (subS.size() % 2 == 0){
      leftS = subS.substr(0, subS.size() / 2);
      rightS = subS.substr(subS.size() / 2, subS.size() / 2);
      if (leftS == rightS){
        maxLength = subS.size();
        break;
      }
    }
    
    
  }

  cout << maxLength << endl;  
}