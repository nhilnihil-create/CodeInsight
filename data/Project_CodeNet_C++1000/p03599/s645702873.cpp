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
#include<cmath>
#include<limits>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
using namespace std;

int gcd(int a, int b) {
	if (a > b) {
		int c = a;
		a = b;
		b = c;
	}
	if (a == 0) {
		return b;
	}

	return gcd(b % a, a);
}

int lcm(int a, int b) {
	int GCD = gcd(a, b);
	return a * b / GCD;
}

bool isValid(int sugar,int Ls,int c,int d) {
	for (int cc = 0; cc <= Ls / c; cc++) {
		for (int dd = 0; dd <= Ls / d; dd++) {
			int k = (sugar - c * cc - d * dd);
			if (k%Ls==0 && k>= 0) return true;
		}
	}

	return false;
}

int main() {
	long double a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
	int Ls = lcm(c, d);
	int L = lcm(a, b);
	long double g = 0;
	vi ans(2);
	for (long double sugar = 0; sugar <= e * f / 100; sugar++) {
		if (!isValid(sugar, Ls, c, d)) continue;

		long double low = sugar / e, high = (f - sugar) / 100;
		int l = int(low), h = int(high);
		l =  l / L;
		h = (h+L-1) / L;
	
		
		for (int t = l; t <= h; t++) {
			bool flag = false;
			for (int aa = 0; aa <= L / a; aa++) {
				for (int bb = 0; bb <= L / b; bb++) {
					long double water = 100 * (t * L + aa * a + bb * b);
					if (water + sugar <= f && water > 0) {
						if (g <= sugar / water && sugar / water <= e/100) {
							//cout << aa << "x" << bb << "x" << t << "s" << sugar << "g" << g << endl;			
							//cout << "water:" << water << endl;
							g = sugar / water;
							ans[0] = water;
							ans[1] = sugar;
							flag = true;
						}
					}
				}
			}
			if (flag) break;
		}
	}
	cout << ans[0] + ans[1] << " " << ans[1] << endl;
}
