#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, a, b;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> a >> b;
	vector<ll> h(n);
	for (int i = 0; i < n; i++) 
      cin >> h.at(i);
	ll l = 0, r = 1000000000;
	while(r - l > 1){
		ll mid = (r + l) / 2, sum = 0;
		for (int i = 0; i < n; i++)
			if(h.at(i) > mid * b) 
             	sum += (h.at(i) - mid * b + (a - b - 1)) / (a - b);
		if(sum <= mid) 
          	r = mid;
		else 
          l = mid;
	}
	cout << r << '\n';
  return 0;
}
