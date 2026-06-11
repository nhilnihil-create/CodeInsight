#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int> cook(3);
  for(int i = 0; i < 3; i++){
    cin >> cook[i];
  }
  sort(cook.begin(),cook.end());
  long long A = cook[0],B = cook[1],C = cook[2];
   for (int i = 0; i < 1000; ++i) {
        if (A & 1){
          cout << i;
          return 0;
        }
        if (B & 1){
          cout << i;
          return 0;
        }
        if (C & 1){
          cout << i;
          return 0;
        }
        long long tA = (B + C) / 2;
        long long tB = (C + A) / 2;
        long long tC = (A + B) / 2;
        A = tA, B = tB, C = tC;
    }
    cout << -1;
}
