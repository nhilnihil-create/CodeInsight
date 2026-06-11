#include <iostream>
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long previous;
  long long UD = 0;
  long long count = 0;
  for (long long i = 0; i < N; i++){
    long long a;
    cin >> a;
    if (i != 0){
      if (UD == 0){
        if (a > previous) UD = 1;
        if (a < previous) UD = -1;
      }
      if (UD == 1){
        if (a < previous){
          count++;
          UD = 2;
        }
      }
      if (UD == -1){
        if (a > previous){
          count++;
          UD = 2;
        }
      }
      if (UD == 2){
        UD = 0;
      }
    }
    previous = a;
  }
  if (UD != 2) count++;
  cout << count << endl;
}