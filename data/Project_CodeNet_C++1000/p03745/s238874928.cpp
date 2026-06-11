#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int A[100010];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  
  int count = 0;
  bool up = false;
  bool down = false;
  for (int i = 1; i < N; i++){
    int dif = A[i] - A[i-1];
    if (dif > 0) up = true;
    if (dif < 0) down = true;
    if (up && down) {
      count++;
      up = down = false;
      continue;
    }
  }
 
  cout << count + 1 << endl;
}