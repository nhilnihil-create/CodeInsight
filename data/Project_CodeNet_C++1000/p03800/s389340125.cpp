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
using namespace std;

bool binalize_ox(char c) {
	if (c == 'o') {
		return 1;
	}
	else {
		return 0;
	}
}

bool binalize_SW(char c) {
	if (c == 'W') {
		return 1;
	}
	else {
		return 0;
	}
}

void visualize(vector<bool> ws) {
	for (int i = 0; i < ws.size(); i++) {

	}
}
int main() {
	int N; cin >> N;
	vector<bool> ox(N);
	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		ox[i] = binalize_ox(c);
	}
	vector<bool> ans;
	for (int f = 0; f < 2; f++) {
		for (int s = 0; s < 2; s++) {
			vector<bool> sw(N);
			sw[0] = f;
			sw[1] = s;
			for (int pos = 2; pos < N; pos++) {
				sw[pos] = sw[pos - 2];
				if (!(ox[pos - 1] ^ sw[pos - 1])) {
					sw[pos] = !sw[pos];
				}
			}
			vector<bool> tmp(N);
			tmp[0] = f; tmp[1] = s;
			for (int i = 0; i < N; i++) {
				int ind_prev = (N + i - 1) % N;
				int ind_next = (N + i + 1) % N;
				if (sw[i] == 0) {
					tmp[i] = !(sw[ind_prev] ^ sw[ind_next]);
				}
				else {
					tmp[i] = sw[ind_prev] ^ sw[ind_next];
				}
			}
			bool fg = true;
			for (int pos = 0; pos < N; pos++) {
				if (tmp[pos] != ox[pos]) {
					fg = false;
					break;
				}
			}
			if (fg == true) {
				ans = sw;
				goto endloop;
			}
		}
	}
endloop:
	if (ans.size() > 0) {
		for (bool b: ans) {
			if (b == true) {
				cout << 'W';
			}
			else {
				cout << 'S';
			}
		}
		cout << endl;
	}
	else {
		cout << -1 << endl;
	}
}