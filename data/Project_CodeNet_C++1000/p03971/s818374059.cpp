#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  int ab = 1;
  int w = 0;
  string S;

  cin >> N >> A >> B >> S;
  for(int i=0;i<N;++i){
    if(S.at(i) == 'a' && w < A+B){
      w+=1;
      cout << "Yes" << endl;
    }else if(S.at(i) == 'b' && w < A+B && ab <= B){
      w += 1;
      ab += 1;
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}
