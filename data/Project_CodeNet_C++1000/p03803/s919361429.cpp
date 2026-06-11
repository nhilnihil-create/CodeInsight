#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   int a, b;
   cin >> a >> b;

   if ((b != 1 && a > b) || (a == 1 && b != a)) {
       cout << "Alice" << endl;
   } else if (a == b) {
       cout << "Draw" << endl;
   } else if ((a != 1 && a < b) || (b == 1 && a != b)){
       cout << "Bob" << endl;
   }
}