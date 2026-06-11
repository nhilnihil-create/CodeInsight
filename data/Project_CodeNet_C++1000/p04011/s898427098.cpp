#include <iostream>
using namespace std;

int main(){
  int N, K, X, Y;
  cin >> N >> K >> X >> Y;

  int result = (N <= K)? (X * N) : (X * K + Y * (N - K));
  cout << result << endl;
}