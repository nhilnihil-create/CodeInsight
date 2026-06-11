#include <iostream>
using namespace std;

int main (){
  long long N, A, B;
  cin >> N >> A >> B;
  if (N != 1 && A <= B){
    cout << (N - 2) * (B - A) + 1 << endl;
  }
  else if (N == 1 && A == B) cout << 1 << endl;
  else cout << 0 << endl;
}