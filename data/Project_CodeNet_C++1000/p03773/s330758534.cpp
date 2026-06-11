#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   int a, b;
   cin >> a >> b;

   if (a+b < 24) {
       cout << a + b << endl;
   } else {
       cout << a + b - 24 << endl;
   }
}