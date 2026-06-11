#include<iostream>
#include<vector>
#include<bitset>

typedef long long ll;

using namespace std;
template <class T>
using mtx = std::vector<std::vector<T>>;

struct cum_sum {
	vector<ll> ar;
	vector<ll> sum;
	int N;
	cum_sum() = default;
	cum_sum(int _N) {
		N = _N;
		ar.resize(N), sum.resize(N + 1);
	}
	cum_sum(vector<ll>& _ar) {
		ar = _ar;
	}

	ll& operator[](int _idx) {
		return ar[_idx];
	}

	void setup() {
		for (int i = 0; i < N; i++) {
			sum[i + 1] = sum[i] + ar[i];
		}
	}
	ll getval(int l, int r) {
		//[l, r)
		ll ret = sum[r] - sum[l];
		return ret;
	}
};

struct cum_sum_lessmemory {
	vector<int> sum;
	int N;
	cum_sum_lessmemory() = default;
	cum_sum_lessmemory(int _N) {
		N = _N;
		sum.resize(N + 1);
	}
	
	void setup(bitset<5000 + 10>& _ar) {
		for (int i = 0; i < N; i++) {
			sum[i + 1] = sum[i] + _ar[i];
		}
	}
	ll getval(int l, int r) {
		//[l, r)
		ll ret = sum[r] - sum[l];
		return ret;
	}
};

int N, K;
vector<ll> a;
bitset<5000 + 10> dpl, dpr;//0-idx

int main() {
	cin >> N >> K;
	a.resize(N);
	for (int i = 0; i < N; i++)cin >> a[i];

	vector<cum_sum_lessmemory> left(N + 10, cum_sum_lessmemory(K + 10)), 
		right(N + 10, cum_sum_lessmemory(K + 10));

	dpl = 1, dpr = 1;
	left[0].setup(dpl), right[0].setup(dpr);
	
	for (int i = 0; i < N; i++) {
		if (a[i] < K) {
			dpl |= (dpl << a[i]);
		}
		left[i + 1].setup(dpl);
	}
	for (int i = N; i > 0; i--) {
		dpr |= (dpr << a[i - 1]);
		right[i - 1].setup(dpr);
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		//i番目を除外する
		if (a[i] >= K)continue;
		bool f = true;
		for (int j = 0; j < K; j++) {
			if (left[i].getval(j, j + 1) == 0)continue;
			if (j >= K - a[i]) {
				f = false;
				break;
			}
			if (right[i + 1].getval(K - a[i] - j, K - j)) {
				f = false;
				break;
			}
		}
		if (f)ans++;
	}
	cout << ans << endl;
	return 0;
}