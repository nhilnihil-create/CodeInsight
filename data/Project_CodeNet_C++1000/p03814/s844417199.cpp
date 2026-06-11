#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int N = S.size();
  int A_min;
  int Z_max;
  int check_A = 0;
  for(int i = 0; i < N; i++){
    char a = S.at(i);
    if(a == 'A' && check_A == 0){
      A_min = i;
      check_A = 1;
    }else if(a == 'Z'){
      Z_max = i;
    }
  }
  cout << Z_max - A_min +1 << endl;
}