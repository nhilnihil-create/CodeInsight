#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
 int W, a, b;
 cin >> W >> a >> b;

 if(a < b) {
   if(a + W > b) { cout << 0; return 0; }

   cout << b - (a + W);
 }
 else if(a == b) { cout << 0; return 0; }
 else {
   if(a < b + W) { cout << 0; return 0; }

   cout << a - (b + W);
 }
  return 0;
}