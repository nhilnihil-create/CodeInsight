#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M, x1, x2;
  cin >> N >> M;
  vector<int> number(N, 0);
  for (int i = 1; i < M + 1; i++){
    cin >> x1 >> x2;
    for (int j = 0; j < N; j++){
      if(x1 == j + 1){
        number.at(j)++;
      }
      if(x2 == j + 1){
        number.at(j)++;
      }
    }
  }
  for (int i = 0; i < N; i++){
    cout << number.at(i) << endl;
  }
  return 0;
}