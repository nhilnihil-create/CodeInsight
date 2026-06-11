#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   int N;
   cin >> N;
   vector<int> A(N);
   for(int i=1; i<=N; i++) {
      cin >> A[i];
   }
   int next = 1;
   int count = 0;
   for(int i=0; i<N; i++) {
      if(next == 2) {
         cout << count << endl;
         return 0;
      }
      next = A[next];
      count++;
   }
   cout << -1 << endl;
}