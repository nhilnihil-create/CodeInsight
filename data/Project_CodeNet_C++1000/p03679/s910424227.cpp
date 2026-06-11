#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   int x, a, b;
   cin >> x >> a >> b;

   if (a >= b) {
       cout << "delicious" << endl;
   } else if ((a + x) >= b){
       cout << "safe" << endl;
   } else {
       cout << "dangerous" << endl;
   }
}