#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(x, a, b) for(int x = (a); x <= (b); ++x)
#define rop(x, a, b) for(int x = (a); x < (b); ++x)
#define per(x, a, b) for(int x = (a); x >= (b); --x)
using namespace std;
typedef long long LL;
typedef double DB;
LL n, x, as;
LL work(LL a, LL b) {
	if(a > b) swap(a, b);
	if(a == 0) return 0;
	return work(a, b % a) + b / a * 2 * a - a * (b % a == 0);
}
int main() {
	cin >> n >> x;
	as += n;
	as += work(x, n - x);
	cout << as << endl;
	return 0;
}
