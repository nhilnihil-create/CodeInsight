#include <iostream>
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long count = 0;
  for (int i = 0; i < N; i++){
    long long a;
    cin >> a;
    if (a % 2 == 1) count++;
  }
  
  if (count % 2 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}