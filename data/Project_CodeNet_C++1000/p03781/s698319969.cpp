#include <iomanip>
#include <random>
#include <time.h>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <string>
#include <cstdlib>
#include <typeinfo>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll cnt[55][26], ans[26];
int main() {
	ll n, now = 0, cnt = 1;
	cin >> n;
	while (1) {
		now += cnt;
		if (now >= n) {
			cout << cnt << endl;
			return 0;
		}
		cnt++;
	}
	return 0;
}