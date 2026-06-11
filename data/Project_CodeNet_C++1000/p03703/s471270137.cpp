#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


class BIT {
private:
    int bit[200010] = {};

public:
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & (-i);
        }
        return s;
    }

    void add(int n, int i, int k) {
        while (i <= n) {
            bit[i] += k;
            i += i & (-i);
        }
    }

};

int main(void) {
	int n, k, i, a[200003];
    ll r[200003] = {}, ans;
    set<ll> s;
    vector<ll> v;

    BIT rd;

	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 1; i <= n; i++) {
		r[i] = r[i - 1] + a[i] - k;
	}

    for (i = 0; i <= n; i++) {
        if (s.find(r[i]) == s.end()) {
            v.push_back(r[i]);
            s.insert(r[i]);
        }
    }

    sort(v.begin(), v.end());

    for (i = 0; i <= n; i++) {
        r[i] = (ll)(lower_bound(v.begin(), v.end(), r[i]) - v.begin() + 1);
    }

    ans = 0;
    for (i = 0; i <= n; i++) {
        ans += rd.sum(r[i]);
        rd.add(n + 1, r[i], 1);
    }

    printf("%lld\n", ans);

	return 0;
}