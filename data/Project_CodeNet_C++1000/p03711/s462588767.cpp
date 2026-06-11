#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  unordered_set<int> st1 = {1, 3, 5, 7, 8, 10, 12};
  unordered_set<int> st2 = {4, 6, 9, 11};

  int a, b;
  cin >> a >> b;

  if ((st1.count(a) && st1.count(b)) ||
      (st2.count(a) && st2.count(b)) || (a == 1 && b == 1)) {
    cout << "Yes" << "\n";
  }
  else cout << "No" << "\n";
}
