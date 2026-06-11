#include <iostream> // cin, cout, cerr, clog
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota, accumulate, inner_product
#include <cstdio> // printf, scanf
#include <climits> // INT_MIN, LLONG_MIN
#include <cmath> // long, trig, pow
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <stack> // stack
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <unordered_map> // hashed by keys
#include <unordered_set> // hashed by keys
#include <iomanip> // cout<<setprecision(n)
#include <functional> // std::function<void(int)>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

#define dump1(v) for(auto i:v) std::cout << i << ' '; std::cout << "\n";
#define dump2(v) for(auto i:v) { for(auto j:i) std::cout << j << ' '; std::cout << "\n"; }


struct BIT
{
	int size;
	std::vector<int> data;
	BIT(int n) : data(n+1,0), size(n) {}
	void add(int i,int v) {
		i+=1;
		while(i<=size) {
			data[i]+=v;
			i += i&-i;
		}
	}
	int query(int l, int r) {
		// [l, r)
		int rv = 0;
		while(r>0) {
			rv+=data[r];
			r -= r&-r;
		}
		int lv = 0;
		while(l>0) {
			lv+=data[l];
			l -= l&-l;
		}
		return rv-lv;
	}
};


int inversion_number(const std::vector<int>& a) {
	int n = a.size();
	std::vector<int> b = a;
	std::sort(all(b));
	std::vector<int> c(n);
	for(int i=0;i<n-1;i++) {
		c[i+1] = c[i];
		if(b[i+1]!=b[i]) c[i+1]++;
	}

	// reconstruct
	std::vector<int> d(n);
	for(int i=0;i<n;i++) {
		d[i] = c[std::lower_bound(all(b),a[i]) - b.begin()];
	}

	BIT bit(n);
	int count = 0;
	for(int i=0;i<n;i++) {
		count += bit.query(0,d[i]+1);
		bit.add(d[i],1);
	}

	return count;
}

signed main() {
	int n,k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	rep(i,n) {
		int x;
		std::cin >> x;
		a[i] = x-k;
	}
	std::vector<int> ac(n,0);
	ac[0] = a[0];
	for(int i=1;i<n;i++) {
		ac[i] = ac[i-1] + a[i];
	}

	int count = 0;
	for(int i:ac) {
		if(i>=0) count++;
	}

	print(inversion_number(ac)+count);

	return 0;
}
