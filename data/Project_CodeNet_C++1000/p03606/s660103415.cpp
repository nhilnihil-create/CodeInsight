#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, i, ri, li, S;
  S = 0;
  i = 0;
  cin >> N;
  while (i < N) {
    cin >> li >> ri;
    S += ri - li + 1;
    i++;
  }
  cout << S << endl;
}
