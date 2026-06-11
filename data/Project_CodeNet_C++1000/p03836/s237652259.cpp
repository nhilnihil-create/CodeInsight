#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
   for (int i = 0; i <c-a; i++) {
     cout << 'R';
   }
  for (int i = 0; i <d-b; i++) {
     cout << 'U';
   }
  for (int i = 0; i <c-a; i++) {
     cout << 'L';
   }
  for (int i = 0; i <d-b; i++) {
     cout << 'D';
   }
  cout << 'D';
  for (int i = 0; i <c-a+1; i++) {
     cout << 'R';
   }
  for (int i = 0; i <d-b+1; i++) {
     cout << 'U';
   }
  cout << 'L';
  cout << 'U';
  for (int i = 0; i <c-a+1; i++) {
     cout << 'L';
   }
  for (int i = 0; i <d-b+1; i++) {
     cout << 'D';
   }
  cout << 'R';
}