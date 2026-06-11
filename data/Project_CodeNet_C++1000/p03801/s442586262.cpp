#include <iostream> // cin, cout, cerr
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota
#include <cstdio> // printf, scanf
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <iomanip> // cout<<setprecision(n)
#include <functional> // function<void(int)>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

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

// requires <BIT>

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
		count += bit.query(0,d[i]);
		bit.add(d[i],1);
	}

	return count;
}


signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	std::vector<int> b = a;
	std::sort(all(b));
	std::vector<int> c(n+1,0);
	rep(i,n) c[i+1] = c[i] + b[i];
	int k = 0;
	int sum = 0;
	rep(i,n) sum+=a[i];
	int lastj = 0;
	rep(i,n) {
		if(a[i] <= k) {
			print(0);
			continue;
		}
		// x<=k are already dead
		int x = a[i];
		int j = std::upper_bound(all(b),x) - b.begin();
		int y = 0;
		y += c[j] - c[lastj] - (j-lastj)*k;
		y += (n-j)*(x-k);
		print(y);
		k = std::max(k,x);
		lastj = j;
	}
	return 0;
}
