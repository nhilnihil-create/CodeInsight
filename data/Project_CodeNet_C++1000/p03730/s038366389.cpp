#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  vector<int> cnt(B);
  int i = 1;
  while(1){
    cnt.at(((A%B)*i)%B) ++;
    if(((A%B)*i)%B == C){
      cout << "YES" << endl;
      return 0;
    }
    if(cnt.at(((A%B)*i)%B) > 1){
      cout << "NO" << endl;
      return 0;
    }
    i++;
  }
}