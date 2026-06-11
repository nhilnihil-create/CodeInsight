#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#include <set>
#include <list>
#include <iomanip>
#include <map>
#include <functional>
#include <string.h>

using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a,0,sizeof(a))
#define minus(a) memset(a,0xff,sizeof(a))
#define chmax(a,b) a=min((a),(b))
#define chmin(a,b) a=max((a),(b))

template <typename T>
class Bit {
public:
	vector<T> a;
	Bit(int n) {
		a.resize(n+1);
	}
	void add(int x, T y) {
		for (int i = x; i < a.size(); i += (i&-i)) {
			a[i] += y;
		}
	}

	T sum(int x) {
		T ret = 0;
		for (int i = x; i > 0; i -= (i&-i)) {
			ret += a[i];
		}
		return ret;
	}
};

typedef tuple<int, int, int>P;
vector<P> lr;
int n, m;


int main(){
	int l, r;
	scanf("%d %d ", &n, &m);
	
	rep(i, n) {
		scanf("%d %d ", &l, &r);
		lr.push_back(P(r - l + 1, l, r));
	}
	sort(all(lr));
	vector<int> width;
	int x, y, w;
	
	rep(i, lr.size()) {
		tie(w,x,y) = lr[i];
		width.push_back(w);
	}
	int up;
	int pos = 0, cur = 0;
	Bit<int> bit(m);
	FOR(d,1,m){//
		int res = 0;
		pos = lower_bound(all(width), d) - width.begin();
		res += n - pos;
		if (pos > cur) {
			while (cur < pos) {
				tie(w,x,y) = lr[cur++];
				bit.add(x, 1);
				bit.add(y + 1, -1);
			}
		}
		
		for (int j = d; j <= m; j += d) {//
			res += bit.sum(j);
		}
		printf("%d\n", res);
	}

	return 0;
}
