#include <iostream>

using namespace std;

int main() {
  int N,A,B,i,mi{1000000001};
  cin >> N;
  while(cin >> A >> B){
    if (B < mi) mi = B, i = A; 
  }
  cout << i+mi << endl;
  return 0;
}
