#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int K, T;
   cin >> K >> T;

   vector<int> a(T);

   int max_T = 0, sum = 0;

   for (int i = 0; i < T; i++) {
     cin >> a.at(i);
     max_T = max(max_T, a.at(i));
     sum += a.at(i);
   }
   cout << max(0, 2 * max_T - sum - 1) << endl;
 }
