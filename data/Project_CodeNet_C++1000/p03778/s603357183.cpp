#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int W, A, B;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> W >> A >> B;
  if(A > B) swap(A, B);
  cout << ((B - (A + W)) > 0 ? (B - (A + W)) : 0) << "\n";
}
