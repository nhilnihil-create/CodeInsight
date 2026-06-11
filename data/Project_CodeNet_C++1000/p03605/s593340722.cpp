#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   int n;
   cin >> n;

   int n1 = n / 10;
   int n2 = n % 10;

   if ((n1 != 0 && n1 % 9 == 0) || (n2 != 0 && n2 % 9 == 0)) {
       cout << "Yes" << endl;
   } else {
       cout << "No" << endl;
   }
}