#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   int A, B, C, D;
   cin >> A >> B >> C >> D;

   if(D <= A || B <= C) {
      cout << 0 << endl;
   }
   else {
      cout << min(B, D) - max(A, C) << endl;
   }
}