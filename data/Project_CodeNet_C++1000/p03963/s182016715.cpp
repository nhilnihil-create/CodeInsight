#include <iostream>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  int a = 1;
  for(int i=0; i<N-1; i++){
    a *= K-1;
  }
  cout << K*a;
  return 0;
}