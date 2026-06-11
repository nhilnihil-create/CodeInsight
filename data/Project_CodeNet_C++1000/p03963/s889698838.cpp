#include <iostream>
using namespace std;

int getResult(const int ball, const int color){
  int result = color;
  for(int i = 1; i < ball; i++){
    result *= (color - 1);
  }
  return result;
}

int main(){
  int N, K;
  cin >> N >> K;
  
  int result = getResult(N, K);
  cout << result;
  return 0;
}