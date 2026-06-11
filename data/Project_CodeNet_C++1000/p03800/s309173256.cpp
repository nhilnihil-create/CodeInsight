//include,using,define等
#pragma region header
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#include <cstring>

// ===============================================================
//using系
#pragma region header
using namespace std;
using ll = long long;
using lint = long long;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using ld = long double;
using ull = unsigned long long;
using ui = unsigned int;
using qul = queue<ll>;
using pql = priority_queue<ll>;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
constexpr ll mod = 1000000007;
constexpr long double pi = 3.141592653589793238462643383279;
#pragma endregion
// ========================================================================
//define
#pragma region header
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i <= n; i++)
#define INF (ll)10000000000000000
#define mod (ll)1000000007
#pragma endregion
#pragma endregion



int main() {
	int n; cin >> n;
	string s; cin >> s;
	for (int a = 0; a < (1 << 2); a++) {
		vector<short> d(n, 2);
		if (a >> 0 & 1) d[0] = 1;
		else d[0] = 0;
		if (a >> 1 & 1) d[1] = 1;
		else d[1] = 0;
		for (int i = 1; i < n - 1; i++) {
			if (d[i] == 1) {
				if (d[i - 1]) {
					if (s[i] == 'o') 
						d[i + 1] = 1;
					else 
						d[i + 1] = 0;
				}
				else {
					if (s[i] == 'o')
						d[i + 1] = 0;
					else
						d[i + 1] = 1;
				}
			}
			else {
				if (d[i - 1]) {
					if (s[i] == 'o')
						d[i + 1] = 0;
					else
						d[i + 1] = 1;
				}
				else {
					if (s[i] == 'o')
						d[i + 1] = 1;
					else
						d[i + 1] = 0;
				}
			}
		}
		//シミュレーション終わり
		//最初と最後の整合性が取れているか
		if (d[0] == 0) {
			if (s[0] == 'o') {
				//d[1]とd[n-1]が違うケース
				if (d[1] == d[n - 1]) continue;
			}
			else if (d[1] != d[n - 1]) continue;
		}
		if (d[0] == 1) {
			if (s[0] == 'o') {
				//d[1]とd[n-1]が同じケース
				if (d[1] != d[n - 1]) continue;
			}
			else if (d[1] == d[n - 1]) continue;
		}
		if (d[n - 1] == 1) {
			if (s[n - 1] == 'o') {
				//d[1]とd[n-1]が同じケース
				if (d[n - 2] != d[0]) continue;
			}
			else if (d[n - 2] == d[0]) continue;
		}
		if (d[n - 1] == 0) {
			if (s[n - 1] == 'o') {
				//d[1]とd[n-1]が違うケース
				if (d[n - 2] == d[0]) continue;
			}
			else if (d[n - 2] != d[0]) continue;
		}
		for (int i = 0; i < n; i++) {
			if (d[i] == 1) cout << 'S';
			else cout << 'W';
		}
		cout << "\n";
		goto kaage;
	}
	cout << -1 << endl;

kaage:;
	return 0;
}