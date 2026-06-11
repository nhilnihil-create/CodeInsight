#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  cin >> S;

  int posA = 0;
  bool findA = false;
  int posZ = 999999;

  for (int i = 0; i < S.size(); i++)
  {
    if (S.at(i) == 'A' && !findA){
      posA = i;
      findA = true;
    }

    if (S.at(i) == 'Z'){
      posZ = i;
    }
  }
  cout << posZ - posA + 1 << endl;
  
}