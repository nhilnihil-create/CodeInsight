#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
   int a, b, c , d;
   cin >> a >> b >> c >> d;
   int ans = min(b,d) - max(a,c);
   if (ans < 0) {
	   ans =0;
   }
   cout << ans;
	return 0;
}

















