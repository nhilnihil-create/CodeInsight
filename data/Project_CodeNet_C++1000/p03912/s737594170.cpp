#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <istream>
#include <ostream>

#include <cstdlib>
#include <cmath>
#include <cstdio>

using namespace std;

#define fi first
#define se second
#define mkp make_pair
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define rep(i,n) for(ll i=0; i < (n); ++i)
#define rrep(i,n) for(ll i=((n)-1); i >= 0; --i)

#define OPLT(T) bool operator<(const T & lop_, const T & rop_)
#define OPEQ(T) bool operator==(const T & lop_, const T & rop_)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

//istream& operator>>(istream& istr, __float128& obj) { double d; istr >> d; obj = d; return istr; };
//ostream& operator<<(ostream& ostr, __float128& obj) { ostr << static_cast<double>(obj); return ostr; };

int r[100100], q[100100];
int cnt[100100];

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> X(N);
	rep(i,N) {
		cin >> X[i];
		cnt[X[i]]++;
	}
	rep(i,100100) {
		r[i%M] += cnt[i]%2;
		q[i%M] += cnt[i]/2;
	}
	int res = 0;
	for(int i = 1; ; i++) {
		int j = M-i;
		if(i >= j) break;
		int qa, qb, ra, rb;
		if(r[i] < r[j]) {
			ra = r[i];
			rb = r[j];
			qa = q[i];
			qb = q[j];
		}
		else {
			ra = r[j];
			rb = r[i];
			qa = q[j];
			qb = q[i];
		}
		// a < b
		res += ra;
		rb -= ra;
		ra = 0;
		res += min(rb, qa*2);
		qa = max(0, (qa*2 - rb)/2);
		res += qa;
		res += qb;
	}
	if(M % 2 == 0) {
		res += q[M/2];
		res += r[M/2]/2;
	}
	res += (q[0]*2+r[0])/2;
	cout << res << endl;
	return 0;
}
