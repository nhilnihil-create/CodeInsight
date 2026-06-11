#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

long long int N, M, K, Q, W, H, L, R;
long long int ans;


int main() {
	ios::sync_with_stdio(false);
	cin >> W >> H;
	vector<pair<long long int, bool>>v(W + H);
	for (int i = 0; i < W; i++) {
		int a;
		cin >> a;
		v[i] = { a,true };
	}
	for (int i = W; i < H + W; i++) {
		int a;
		cin >> a;
		v[i] = { a,false };
	}
	sort(v.begin(), v.end());
	H++;
	W++;
	for (auto i : v) {
		if (i.second) {
			ans += i.first*H;
			W--;
		}
		else {
			ans += i.first*W;
			H--;
		}
	}
	cout << ans << endl;
	return 0;
}