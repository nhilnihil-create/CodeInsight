#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> number1(M);
  vector<int> number2(M);
  vector<int> sum(N);
  for(int i = 0; i < M; i++){
    cin >> number1.at(i) >> number2.at(i);
  }
  for(int i = 0; i < N; i++){
    for(int a = 0; a < M; a++){
      if(number1.at(a) == i + 1){
        sum.at(i)++;
      }
      if(number2.at(a) == i + 1){
        sum.at(i)++;
      }
    }
    cout << sum.at(i) << endl;
  }
}
