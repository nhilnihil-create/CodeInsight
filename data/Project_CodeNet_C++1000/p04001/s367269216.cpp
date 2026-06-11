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
#include<math.h>
#define rep(i,n) for(int i = 0;i<(int)(n);i++);
using namespace std;
using ll = long long;
const ll INF = 100100100100100;
ll keta(ll x) {
	ll sum = 0;
	while (x) {
		x /= 10;
		sum++;
	}
	return sum;
}
int main() {
	ll S;
	cin >> S;
	ll size = 0;
	ll ans = 0;
	ll now = 0;
	size = keta(S);
	vector<ll> num(size);//入力された数字を１つずつ配列に入れる
	for (int i = 0; i < size; i++) {
		num[size - 1 - i] = S % 10;
		S /= 10;
	}
	for (int i = 0; i < (1 << (size - 1)); i++) {
		bitset<9> s(i); {//０の時は+は無し１の時は+とする
			for (int j = 0; j < size - 1; j++) {
				now = now * 10 +num[j];
				if (s.test(j)) {//１の場合
					ans += now;
					now = 0;
				}
			}
			now = now * 10 + num[size - 1];
			ans += now;
			now = 0;
		}
	}
	cout << ans << '\n';
}