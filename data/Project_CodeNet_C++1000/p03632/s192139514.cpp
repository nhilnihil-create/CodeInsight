#include<bits/stdc++.h>
using namespace std;

int main() {
   int A, B, C, D;
   cin >> A >> B >> C >> D;
   if (B<C || D<A) {
       cout << "0\n";
       return 0;
   }
   else cout << min(D,B) - max(A,C) << "\n";
}