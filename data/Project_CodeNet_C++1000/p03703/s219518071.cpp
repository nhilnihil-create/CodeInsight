
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl;
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)
#define INF INT_MAX/2

template<typename T>
struct BIT {
	int n;
	vector<T>dat;
	BIT(int n = 0) {
		initialize(n);
	}
	void initialize(int temp) {
		n = temp;
		dat.resize(n);
		rep(i, 0, n)dat[i] = 0;
	}
	T sum(int i) {
		T s = 0;
		while (i >= 0) {
			s += dat[i];
			i = (i & (i + 1)) - 1;
		}
		return s;
	}
	T sum_between(int i, int j) {
		if (i > j)return 0;
		return sum(j) - sum(i - 1);
	}
	void plus(int i, T x) {
		while (i < n) {
			dat[i] += x;
			i |= i + 1;
		}
	}
	int lower_bound(T x) {
		if (sum(n - 1) < x)return -1;
		else if (sum(0) >= x)return 0;
		int ng = 0, ok = n - 1;
		while (ok - ng > 1) {
			int mid = (ok + ng) / 2;
			if (sum(mid) >= x)ok = mid;
			else ng = mid;
		}
		return ok;
	}
};

ll sum[202020];
int main() {
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	rep(i, 0, n) {
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	rep(i, 0, n + 1)sum[i] = sum[i] - k * i;

	vector<ll>dic;
	rep(i, 0, n+1)dic.pb(sum[i]);
	sort(all(dic));
	dic.erase(unique(all(dic)),dic.end());
	int sz = dic.size();
	BIT<ll>bitnum(sz);

	rep(i, 0, n + 1) {
		int ind = lower_bound(all(dic),sum[i]) - dic.begin();
		bitnum.plus(ind,1);
	}

	ll ans = 0;
	rep(l, 0, n) {
		int ind = lower_bound(all(dic), sum[l]) - dic.begin();
		ans += bitnum.sum_between(ind,sz-1)-1;
		bitnum.plus(ind, -1);
	}
	puts(ans)

	return 0;
}
