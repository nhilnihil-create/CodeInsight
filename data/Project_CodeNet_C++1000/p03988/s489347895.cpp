#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod (ll)1000000007
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, a[110];
multiset<int> st;
signed main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		st.insert(a[i]);
	}
	sort(a, a + n);
	if (a[n - 1] != a[n - 2]) {
		puts("Impossible");
		return 0;
	}
	st.erase(st.find(a[n - 1]));
	st.erase(st.find(a[n - 1]));
	for (int i = a[n - 1] - 1; i * 2 >= a[n - 1]; i--) {
		if (i * 2 > a[n - 1]){
			if (st.count(i) < 2) {
				puts("Impossible");
				return 0;
			}
			st.erase(st.find(i));
			st.erase(st.find(i));
		}
		if (i * 2 == a[n - 1]){
			if (!st.count(i)) {
				puts("Impossible");
				return 0;
			}
			st.erase(st.find(i));
		}
	}
	if (st.empty())puts("Possible");
	else if ((*st.begin() - 1) >= (a[n - 1] + 1) / 2)puts("Possible");
	else puts("Impossible");
	return 0;
}