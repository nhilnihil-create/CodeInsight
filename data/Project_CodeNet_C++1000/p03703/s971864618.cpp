#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template <class Abel> struct BIT {
	vector<Abel> dat;
	Abel UNITY_SUM = 0;

	// [1, n]
	BIT(int n) {
		dat.resize(n+1);
		for(int i=0;i<(int)dat.size();i++) {
			dat[i] = UNITY_SUM;
		}
	}

	// a is 1-indexed
	inline void add(int a, Abel x) {
		for(int i=a;i<(int)dat.size();i += i & -i) {
			dat[i] = dat[i] + x;
		}
	}

	// [1, a], a is 1-indexed
	inline Abel sum(int a) {
		Abel res = UNITY_SUM;
		for(int i=a;i>0;i -= i & -i) {
			res += dat[i];
		}
		return res;
	}

	// [a, b), a and b are 1-indexed
	inline Abel sum(int a, int b) {
		return sum(b - 1) - sum(a - 1);
	}
};

int main() {
	int N;
	ll K;
	cin >> N >> K;
	vector<ll> A(N);
	for(auto &a : A) cin >> a;
	
	vector<ll> B(N+1, 0), C(N+1, 0);
	for(int i=1;i<=N;i++) {
		B[i] = B[i-1] + A[i-1];
	}
	for(int i=1;i<=N;i++) {
		B[i] -= (i * K);
		C[i] = B[i];
	}
	
	sort(C.begin(), C.end());
	C.erase(unique(C.begin(), C.end()), C.end());

	// 0 <= j < i <= Nのとき, Bi >= Bjの個数
	ll ans = 0;
	BIT<ll> bit(N+1);
	bit.add((int)(lower_bound(C.begin(), C.end(), 0) - C.begin()) + 1, 1);
	for(int i=1;i<=N;i++) {
		int b = (int)(lower_bound(C.begin(), C.end(), B[i]) - C.begin()) + 1;
		ans += bit.sum(b);
		bit.add(b, 1);
	}
	cout << ans << endl;
}