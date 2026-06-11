#include <iostream>
#include <string>
using namespace std;


int main() {
  int N, K;
  cin >> N >> K;
  long long pattern = 1;

  for(int i = 1; i < N; ++i){
    pattern *= K - 1;
  }
  cout << pattern * K << endl;

  return 0;
}

