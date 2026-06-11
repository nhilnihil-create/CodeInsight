#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, A, B;
  string s;
  cin >> N >> A >> B >> s;
  int jap = 0, over = 0;
  for(int i = 0; i < N; i++){
    if(s.at(i) == 'a' && jap + over < A + B){
      cout << "Yes" << endl;
      jap++;
    }
    else if(s.at(i) == 'b' && jap + over < A + B && over < B){
      cout << "Yes" << endl;
      over++;
    }
    else cout << "No" << endl;
  }
  return 0;
}