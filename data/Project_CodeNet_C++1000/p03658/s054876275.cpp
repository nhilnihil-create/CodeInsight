#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[55], n, k, ans=0;
int main() {
   cin >> n >> k;
   for (int i=0; i<n; i++) cin >> a[i];
   sort(a, a+n);
   k++;
   while (k--) ans+=a[n-k];
   cout << ans;
}