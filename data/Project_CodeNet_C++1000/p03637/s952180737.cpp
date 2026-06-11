#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define inf 10000000
using namespace std;

int main() {
	int N; cin >> N;
	int list[3];
	list[0] = 0, list[1] = 0, list[2] = 0;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (x % 4 == 0) {
			list[0]++;
		}
		else if (x % 2 == 0) {
			list[1]++;
		}
		else {
			list[2]++;
		}
	}

	bool flag = false;
	if (list[1] == 0) {
		if (list[2] <= list[0] + 1) {
			flag = true;
		}
		else {
			flag = false;
		}
	}
	else {
		if (list[2] <= list[0]) {
			flag = true;
		}
		else {
			flag = false;
		}
	}

	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}