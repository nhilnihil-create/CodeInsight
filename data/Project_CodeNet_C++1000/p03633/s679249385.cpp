#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <cstring>
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
#include <cmath>
#include <numeric>
#include <float.h>
#include <math.h>
#include <sstream>
using namespace std;
// repマクロの定義
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// allマクロの定義
#define all(v) v.begin(), v.end()
const  long long INF = 1LL << 60;
typedef  long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int ctoi(char c) {
 	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}

auto my_lcm(auto n , auto m){
	auto a = n;
	auto b = m;
  if(n < m){
    auto tmp = n;
    n = m;
    m = tmp;
  }
  auto l  = n % m;
  while(l != 0){
    n = m;
    m = l;
    l = n % m;
}
return (a / m) * (b/m) * m;
}

int main(){ 
int N; cin >> N;
vector<ll> T(N);
rep(i,N) cin >> T[i];
ll a = 1;
rep(i,N){
	a = my_lcm(a,T[i]);
}
cout << a << endl;
}
