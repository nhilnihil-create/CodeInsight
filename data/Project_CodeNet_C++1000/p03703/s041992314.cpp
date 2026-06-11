#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define mod 1000000007

class BIT {
  private:
	vector<int> v;
	int n;

  public:
	BIT(int m) {
		n = m;
		v = vector<int>(n + 1, 0);
	}

	void add(int x, int val) {
		while (x <= n) {
			v[x] += val;
			x += (x & -x);
		}
	}

	// x以下の値の数を返す
	int getCntOfLTEX(int x) {
		int ans = 0;
		while (x > 0) {
			ans += v[x];
			x -= (x & -x);
		}
		return ans;
	}
};

vector<long long int> compress(vector<long long int> v) {
	set<long long int> s;
	for (int i = 0; i < v.size(); i++) {
		s.insert(v[i]);
	}
	map<long long int, int> m;
	int cnt = 1;
	for (auto itr = s.begin(); itr != s.end(); itr++) {
		m[*itr] = cnt;
		cnt++;
	}
	for (int i = 0; i < v.size(); i++) {
		v[i] = m[v[i]];
	}
	return v;
}

int main() {
	long long int n, k;
	cin >> n >> k;
	// suma[i] = a_0 + a_1 + ... a_{i - 1}
	vector<long long int> suma(n + 1, 0);
	for (int i = 0; i < n; i++) {
		long long int a;
		cin >> a;
		suma[i + 1] = suma[i] + a;
	}
	//   a[l] ... a[r - 1]間の平均は(suma[r] - suma[l]) / (r - l)
	// よって (suma[r] - suma[l]) / (r - l) >= k
	// となるような(l,r)のペアを探せば良い
	//   (suma[r] - suma[l]) / (r - l) >= k
	// <=> suma[r] - suma[l] >= k * (r - l)
	// <=> suma[r] - k * r >= suma[l] - k * l
	// <=> suma[r] >= suma[l] (suma[i] = suma[i] - k * i)
	for (long long int i = 1; i <= n; i++) {
		suma[i] = suma[i] - k * i;
	}
	suma = compress(suma);
	BIT bit(n + 1);
	long long int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += bit.getCntOfLTEX(suma[i]);
		bit.add(suma[i], 1);
		// cout << ans << endl;
	}
	cout << ans << endl;
}