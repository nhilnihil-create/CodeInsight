#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;
  cin >> A >> B >> C;
  for(int i=1; i<=B;i++){
    int X = A*i;
    if(X%B == C){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
