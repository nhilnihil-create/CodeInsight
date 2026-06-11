#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

/*int f(int a, int b, int c) {
	if (b < a) {
		swap(a, b);
	}
	if (c < b) {
		swap(b, c);
		if (b < a) {
			swap(a, b);
		}
	}
	return b;
}

int get(vector<int> kek) {
	while (SZ(kek) > 1) {
		vector<int> kek2;
		for (int i = 1; i + 1 < SZ(kek); i++) {
			kek2.pb(f(kek[i - 1], kek[i], kek[i + 1]));
		}
		kek = kek2;
	}
	return kek.back();
}*/

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  /*vector<int> order;
  int n = 11;
  for (int i = 1; i <= n; i++) {
  	order.pb(i);
  }
  vector<bool> used(n + 1);
  do {
  	int x = get(order);
  	if (!used[x]) {
  		used[x] = true;
  		cout << x << " :    ";
  		for (auto it : order) {
  			cout << it << ' ';
  		}
  		cout << '\n';
  	}
  } while (next_permutation(all(order)));*/
  int n, k;
  cin >> n >> k;
  n = 2 * n - 1;
  vector<int> ans(n + 1);
  vector<bool> used(n + 1);
  if (n == 3) {
  	if (k == 2) {
  		cout << "Yes\n1\n2\n3\n";
  	}
  	else {
  		cout << "No\n";
  	}
  }
  else {
  	if (k == 1 || k == n) {
  		cout << "No\n";
  	}
  	else {
  		cout << "Yes\n";
  		ans[(n + 1) / 2] = k;
  		ans[(n + 1) / 2 - 1] = k - 1;
  		ans[(n + 1) / 2 + 1] = k + 1;
  		used[k] = used[k - 1] = used[k + 1] = true;
  		if (k > 3) {
  			ans[(n + 1) / 2 + 2] = k - 2;
  			used[k - 2] = true;
  		}
  		else {
  			ans[(n + 1) / 2 - 2] = k + 2;
  			used[k + 2] = true;
  		}
  		int ptr = 1;
  		for (int i = 1; i <= n; i++) {
  			if (ans[i]) {
  				cout << ans[i] << '\n';
  			}
  			else {
  				while (used[ptr]) {
  					ptr++;
  				}
  				used[ptr] = true;
  				cout << ptr << '\n';
  			}
  		}
  	}
  }
} 