#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b;

int main() {
  cin >> a >> b;
  if(a > b) swap(a, b);
  puts(b-a < 2 ? "Brown" : "Alice");
  return 0;
}