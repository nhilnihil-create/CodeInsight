#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <cstdlib>
#define rep(i,n) for(int i = 0;i<(n);i++);
#define all(a) (a).begin(),(a).end()
using namespace std;
using ld = long double;
using ll = long long;
const ll INF = 100100100100100;
ll cost(vector<ll> n, ll m) {
	ll ans = 0;
	ll big = n.size();
	for (int i = 0; i < big; i++) {
		ans += pow(m - n[i], 2);
	}
	return ans;
}
int main() {
	ll N;
	cin >> N;
	vector<ll> num(N);
	ll avr1 = 0,avr2 = 0;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		avr1 += num[i];
	}
	avr1 /= N;
	avr2 = avr1 + 1;
	ll cnt = min(cost(num, avr1), cost(num, avr2));
	cout << cnt << endl;
}