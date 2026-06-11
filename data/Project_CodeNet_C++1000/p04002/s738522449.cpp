#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"

#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nya_n "(=^･ω･^=)"
typedef long long ll;
using namespace std;

int h, w, n, a[100000], b[100000];
ll cnt[10];
map<pair<int, int>, pair<int,bool>>mp;

int main() {
	cin >> h >> w >> n;
	lp(n) {
		cin >> a[i] >> b[i];
		for (int j = a[i] - 2; j <= a[i]; j++)
			for (int k = b[i] - 2; k <= b[i]; k++)
				if (mp.find(make_pair(j, k)) == mp.end()) {
					mp[make_pair(j, k)] = make_pair(1, false);
				}
				else mp[make_pair(j, k)].first++;
	}
	lp(9) {
		cnt[i + 1] = 0;
	}
	cnt[0] = ll(h - 2)*ll(w - 2);
	lp(n) {
		for (int j = a[i] - 2; j <= a[i]; j++)
			for (int k = b[i] - 2; k <= b[i]; k++)
				if (!mp[make_pair(j, k)].second && 0 < j&&j <= h-2 && 0 < k&&k <= w-2) {
					cnt[0]--;
					cnt[mp[make_pair(j, k)].first]++;
					mp[make_pair(j, k)].second = true;
				}
	}
	lp(10)
		cout << cnt[i] << endl;
	return 0;
}