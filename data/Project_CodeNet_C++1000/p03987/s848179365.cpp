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

#define MOD 1000000007
#define INIT -1

int main() {
	int n;
	cin >> n;
	long long int place[200010];
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		place[a] = i;
	}
	set<int> s;
	long long int ans = 0;
	s.insert(place[1]);
	ans += (place[1] + 1) * (n - place[1]);
	for (long long int i = 2; i <= n; i++) {
		// cout << ans << endl;
		auto itr = s.upper_bound(place[i]);
		if (itr == s.begin()) {
			ans += i * (place[i] + 1) * (*itr - place[i]);
		} else if (itr == s.end()) {
			itr--;
			ans += i * (place[i] - *itr) * (n - place[i]);
		} else {
			auto previtr = itr;
			previtr--;
			ans += i * (place[i] - *previtr) * (*itr - place[i]);
		}
		s.insert(place[i]);
	}
	cout << ans << endl;
}