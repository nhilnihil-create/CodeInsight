#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <assert.h>
#include <cmath>
#include <stack>
#include <deque>
#include <set>
#include <unordered_map>
#include <complex>
#include <fstream>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
const int mxn = 1e5+10;
const int mod = 1e9+7;
const int inf = 2e9+10;
long long a[mxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k; cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];

	vector<long long> onlyPositive(n+1, 0);
	for(int i=1; i<=n; i++) if(a[i]>0) onlyPositive[i] = a[i];

	vector<long long> onlyPositivePref(n+1, 0);
	for(int i=1; i<=n; i++) onlyPositivePref[i] = onlyPositivePref[i-1]+1ll*onlyPositive[i];
	vector<long long> normalPref(n+1, 0);
	for(int i=1; i<=n; i++) normalPref[i] = normalPref[i-1]+1ll*a[i];

	long long mx = 0;
	for(int i=k; i<=n; i++) {
		long long Black = normalPref[i]-normalPref[i-k]+onlyPositivePref[i-k]+(onlyPositivePref[n]-onlyPositivePref[i]);
		long long White = onlyPositivePref[i-k]+(onlyPositivePref[n]-onlyPositivePref[i]);
		mx = max(mx, max(Black, White));
	}

	cout << mx << '\n';

	return 0;
}
//comparator function in sorting
//swapping arguments
//missing cases in dp
//dividing in modulo
//Beware of overflow and modulo
//Be mindful of overflow
//s is a matrix but forget
//length of ranges
//working with bit using ull