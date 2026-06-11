#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[55], x, y, n, m;
int main() {
   cin >> n >> m;
   while (m--) {
       cin >> x >> y;
       a[x]++; a[y]++;
   }
   for (int i=1; i<=n; i++) cout << a[i] << endl;
}