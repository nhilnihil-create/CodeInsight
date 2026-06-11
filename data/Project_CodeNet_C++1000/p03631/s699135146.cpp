#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;
  int n = N.size();
  for (int i=0; i<n; i++){
   if (N.at(i)!=N.at(n-i-1)) {
     cout << "No" << endl;break;
   }
   if (i==n-1) cout << "Yes" << endl;
  }
}
