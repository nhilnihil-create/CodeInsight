#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int x, t;
  cin >> x >> t;

  cout << max(0, x - t) << endl;
}
