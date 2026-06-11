#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   vector<int> a(3);
   rep(i, 3) {
       cin >> a[i];
   }

   sort(a.begin(), a.end());

   if (a[0] == a[1] && a[1] == a[2]) {
       cout << 1 << endl;
   } else if (a[0] == a[1] || a[1] == a[2]) {
       cout << 2 << endl;
   } else {
       cout << 3 << endl;
   }
}