#include <bits/stdc++.h>
using namespace std;
int main() {
  int pool[2] = {0, 0};
  int n, a, b; cin >> n >> a >> b;
  string v; cin >> v; 
  for (int i = 0; i < n; ++i) {
    if (v[i] == 'c') {
      	puts("No");
      	continue;
    }
    if (v[i] == 'a' && pool[0] + pool[1] < a + b) puts("Yes"), ++pool[0];
    else if (v[i] == 'b' && pool[0] + pool[1] < a + b && pool[1] < b) puts("Yes"), ++pool[1];
    else puts("No");
  }
}