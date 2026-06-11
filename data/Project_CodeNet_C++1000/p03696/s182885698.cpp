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
#define int ll
signed main() {
	int N; cin >> N;
	string s; cin >> s;
	int left_blacket = 0, right_blacket = 0;
	for (int i = 0; i < N; i++) {
		string c = s.substr(i, 1);
		if (c == ")") {
			if (right_blacket > 0) {
				right_blacket--;
			}
			else {
				left_blacket++;
			}
		}
		else {
			right_blacket++;
		}
	}
	for (int t = 0; t < right_blacket; t++) {
		s += ")";
	}
	reverse(ALL(s));
	for (int t = 0; t < left_blacket; t++) {
		s += "(";
	}
	reverse(ALL(s));
	cout << s << endl;
}

/*


		*/