#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
   int n;
   cin >> n;
   int ans = 0;
   for (int i = 0; i < n; ++i) {
	   int x, y;
	   cin >> x >> y;
	   ans += y - x + 1;
   }
   cout << ans;
}

















