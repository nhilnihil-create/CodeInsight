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
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;
vector<long long int>box;
vector<vector<int>>edge;
vector<long long int>up;
vector<bool>flag;
bool can = true;

long long int Search(int num) {
	if (up[num] != -1) {
		return up[num];
	}
	if (edge[num].size() == 1) {
		up[num] = box[num];
		return up[num];
	}
	flag[num] = false;
	long long int sum = 0;
	long long int ma = 0;
	for (auto i : edge[num]) {
		if (flag[i]) {
			long long int fig = Search(i);
			sum += fig;
			ma = max(ma, fig);
		}
	}
	R = sum;
	L = max((sum + 1) / 2, ma);
	if (L > box[num] || R < box[num]) {
		can = false;
	}
	up[num] = box[num] * 2 - sum;
	if (up[num] < 0) {
		can = false;
	}
	return up[num];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	box.resize(N + 1);
	edge.resize(N + 1);
	up.resize(N + 1,-1);
	flag.resize(N + 1, true);
	for (int i = 1; i <= N; i++) {
		cin >> box[i];
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> L >> R;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	if (N == 2) {
		if (box[1] == box[2]) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		if (edge[i].size() != 1) {
			if (!Search(i) && can) {
				cout << "YES\n";
				return 0;
			}
			cout << "NO\n";
			return 0;
		}
	}
	return 0;
}
