#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using lint = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class segment_tree {
private:

	int size;
	vector<int>dat;
	int identity;

	int query_sub(int a, int b, int k, int l, int r) const {
		if (r <= a || b <= l) return identity;
		if (a <= l && r <= b) return dat[k];
		int vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(vl, vr);
	}

public:

	segment_tree(int size_, int identity)
		:identity(identity)
	{
		int x = 1;
		while (size_ > x) x <<= 1;
		size = x;
		dat.resize(2 * size - 1, identity);
	}

	void update(int i, int x) {
		i += size - 1;
		dat[i] = x;
		while (i > 0) {
			i = (i - 1) / 2;
			dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
		}
	}

	// [a, b)
	int query(int a, int b) const { return query_sub(a, b, 0, 0, size); }

	const int& operator[](size_t index) const { return dat[index + size - 1]; }
	int& operator[](size_t index) { return dat[index + size - 1]; }
};

int n;
lint sum;
int main() {
	scanf("%d", &n);

	segment_tree seg(n, 10000000);

	rep(i, n) {
		int a;
		scanf("%d", &a);
		seg.update(i, a);
	}

	rep(i, n) {
		const int a = seg[i];

		lint cnt1, cnt2;

		int l = -1, r = i;
		while (abs(r - l) > 1) {
			int mid = l + (r - l) / 2;
			if (seg.query(mid, i + 1) == a) r = mid;
			else l = mid;
		}

		cnt1 = i - r + 1;

		l = i, r = n;
		while (abs(r - l) > 1) {
			int mid = l + (r - l) / 2;
			if (seg.query(i, mid + 1) == a) l = mid;
			else r = mid;
		}

		cnt2 = l - i + 1;

		sum += cnt1 * cnt2 * a;
	}

	cout << sum << endl;
}