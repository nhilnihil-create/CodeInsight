#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int N;
   cin >> N;

   vector<int> A(N), B(N);
   int max_A = 0, max_i;
   for (int i = 0; i < N; i ++) {
     cin >> A.at(i) >> B.at(i);
     if (A.at(i) > max_A) {
       max_A = A.at(i);
       max_i = i;
     }
   }

   cout << max_A + B.at(max_i) << endl;
  }
