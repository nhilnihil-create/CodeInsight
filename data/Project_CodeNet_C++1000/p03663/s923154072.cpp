#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define int long long
#define MOD7 1000000007
#define MOD9 1000000009

#define rep(i, n) for (int i = 0; i < (n); i++)
#define itrep(i, a) for (auto i = (a).begin(); i != (a).end(); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

template<class T> void inputVector(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}

int N;

bool query(int num) {
	cout << "? " << num << endl;
	cout.flush();

	char ch;

	cin >> ch;

	//if (num <= N && to_string(num) <= to_string(N)) ch = 'Y';
	//else if (num > N && to_string(num) > to_string(N)) ch = 'Y';
	//else ch = 'N';
	//cerr << ch << endl;

	return ch == 'Y';
}

signed main() {
	// cin >> N;

	int pow10[10];
	{
		int tmp = 1;
		rep(i, 10) {
			pow10[i] = tmp;
			tmp *= 10;
		}
	}

	int keta = 0;
	{
		int low = 0;
		int high = 10;
		int mid = (high + low) / 2;
		while (high - low > 1) {
			int num = 1;
			rep(i, mid) num *= 10;
			if (query(num)) {
				low = mid;
			} else {
				high = mid;
			}
			mid = (high + low) / 2;
		}
		keta = mid;
	}

	int state = 0;
	int tmp = 0;

	int cr = 0;
	for (int i = keta - 1; keta >= 0; keta--) {
		int low = 0;
		int high = 10;
		int mid = (high + low + 1) / 2;
		while (high - low > 1) {
			int num = mid;
			rep(j, keta) num *= 10;
			num += cr;
			num *= 10;

			if (!query(num)) {
				low = mid;
			} else {
				high = mid;
			}
			mid = (high + low) / 2;
		}

		if (mid != 0 && mid != 9) state = -1;
		else if (state == 0 && mid == 9) {
			tmp++;
		}

		rep(j, keta) mid *= 10;
		cr += mid;
	}

	cr++;

	if (state == 0) {
		cr = pow10[tmp + 1];
	}

	if (cr == 10) {
		if (query(9)) cr = 1;
	}

	cout << "! " << cr << endl;
	cout.flush();

    return 0;
}
