#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

class Add_Segment_Tree {
	vector<long long int>v;
	vector<int>l;
	vector<int>r;
	long long int ret;
	int num;
	long long int Update(int place) {
		if (place >= v.size() / 2) {
			return v[place];
		}
		v[place] = Update(place * 2) + Update(place * 2 + 1);
		return v[place];
	}
	void Sum(int a, int b, int place) {
		if (l[place] >= a && r[place] <= b) {
			ret += v[place];
			return;
		}
		if (l[place] > b || r[place] < a) return;
		Sum(a, b, place * 2);
		Sum(a, b, place * 2 + 1);
		return;
	}
public:
	void Left(int place) {
		if (place >= v.size() / 2) {
			l[place] = place - v.size() / 2;
			return;
		}
		Left(place * 2);
		Left(place * 2 + 1);
		l[place] = l[place * 2];
		return;
	}
	void Right(int place) {
		if (place >= v.size() / 2) {
			r[place] = place - v.size() / 2;
			return;
		}
		Right(place * 2);
		Right(place * 2 + 1);
		r[place] = r[place * 2 + 1];
		return;
	}
	Add_Segment_Tree(int n) {
		n++;
		num = 1;
		while (num < n * 2)num *= 2;
		l.resize(num);
		r.resize(num);
		v.resize(num, 0);
		Left(1);
		Right(1);
	}
	void Add(int place, long long int num, bool update) {
		place += v.size() / 2;
		v[place] += num;
		if (!update)return;
		place /= 2;
		while (place) {
			v[place] = v[place * 2] + v[place * 2 + 1];
			place /= 2;
		}
	}
	void TopDown() {
		Update(1);
	}
	long long int Sum(int a, int b) {
		ret = 0;
		Sum(a, b, 1);
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	Add_Segment_Tree one(N * 2 + 3);
	for (int i = 0; i <= 2; i++) {
		one.Add(i, 1, true);
	}
	for (int i = 3; i <= N * 2; i++) {
		long long int box = one.Sum(i - 1, i - 1);
		box += one.Sum(max(0, i - (int)N - 1), min((int)N - 2, i - 3));
		box %= MOD;
		one.Add(i, box, true);
	}
	long long int ans = 0;
	long long int by = N - 1;
	by *= N - 1;
	by %= MOD;
	for (int i = 0; i <= N - 2; i++) {
		ans += one.Sum(i, i)*by;
		ans %= MOD;
	}
	ans += one.Sum(N - 1, N - 1)*N;
	ans %= MOD;
	ans += one.Sum(2 * N, 2 * N);
	ans %= MOD;
	ans += MOD;
	ans -= one.Sum(N - 1, N - 1);
	ans %= MOD;
	cout << ans << endl;
	return 0;
}