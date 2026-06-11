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
using namespace std;
using ll = long long;
const ll INF = 100100100100100;
const ll mod = 1000000007;

int main()
{
	ll N;
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	ll odd = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] % 2 == 1) odd++;
	}
	if (odd % 2 == 1) cout << "NO" << endl;
	else cout << "YES" << endl;
}
