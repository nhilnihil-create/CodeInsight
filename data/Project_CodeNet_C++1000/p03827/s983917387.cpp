#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin >> N >> S;
  int m = 0, count = 0;
  for(int i = 0; i < N; i++){
    if(S.at(i) == 'I'){
      count++;
    }
    else count--;
    m = max(m, count);
  }
  cout << m << endl;
}
