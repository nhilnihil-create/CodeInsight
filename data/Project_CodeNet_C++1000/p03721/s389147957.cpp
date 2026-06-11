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

int main() {
	ll N, K;
	cin >> N >> K;//左から k個
    vector<pair<ll,ll>> p(N);
	for (int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;
        p[i] = {a,b};
    }
    sort(p.begin(),p.end());
	ll cnt = 0;
	ll ans = 0;
	while (K) {//Kからb[cnt]を引いていき、0を下回ったらストップ
		if (p[cnt].second >= K) {
			ans = cnt;
			K = 0;
		}
		else {
			K -= p[cnt].second;
			cnt++;
		}
	}
	cout << p[ans].first << endl;
}
