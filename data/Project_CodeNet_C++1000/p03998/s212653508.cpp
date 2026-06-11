#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   string S_A, S_B, S_C;
   cin >> S_A >> S_B >> S_C;
   int A_count = 0, B_count = 0, C_count = 0;

   char turn = 'a';
   for(;;) {
         if(turn == 'a') {
         if(A_count == S_A.size()) {
            cout << 'A' << endl;
            return 0;
         }
         turn = S_A[A_count];
         A_count++;
         }

      if(turn == 'b') {
         if(B_count == S_B.size()) {
            cout << 'B' << endl;
            return 0;
         }
         turn = S_B[B_count];
         B_count++;
      }

      if(turn == 'c') {
         if(C_count == S_C.size()) {
            cout << 'C' << endl;
            return 0;
         }
         turn = S_C[C_count];
         C_count++;
      }
   }
}