#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, L, R, i;
  cin >> N;
  int S = 0;
  for(i = 0;i < N;i++){
    cin >> L >> R;
   S = S + R - L + 1;
  }
  cout << S << endl;
}