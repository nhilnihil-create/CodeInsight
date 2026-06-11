#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;
 #define rep(i, n) for(int i = 0; i < (int)(n); i++)

 int main() {
   int N, count = 0;
   cin >> N;
   vector<int> A(N);
   rep(i, N) {
     cin >> A.at(i);
     if (A.at(i) % 2 == 1) count++;
   }
   if (count % 2 == 0) cout << "YES" << endl;
   else cout << "NO" << endl;
 }
