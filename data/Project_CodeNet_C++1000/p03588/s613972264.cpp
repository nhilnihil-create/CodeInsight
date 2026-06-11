#include <iostream>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N,A,B,i,mi{1000000001};
  cin >> N;
  while(cin >> A >> B){
    if (B < mi) mi = B, i = A; 
  }
  cout << i+mi << endl;
  return 0;
}
