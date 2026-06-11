#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S;
   cin >> S;

   sort(S.begin(), S.end());
   int ans = 0;
   for (int i = 1; i < S.size(); ++i) {
     if (S.at(i - 1) == S.at(i)) {
       cout << "no" << endl;
       return 0;
     }
   }

   cout << "yes" << endl;
  return 0;
}
