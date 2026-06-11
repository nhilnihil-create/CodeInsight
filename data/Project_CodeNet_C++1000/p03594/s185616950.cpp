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

istream& operator>>(istream& istr, __float128& obj) { double d; istr >> d; obj = d; return istr; };
ostream& operator<<(ostream& ostr, __float128& obj) { ostr << static_cast<double>(obj); return ostr; };

int p[1100][2100];

int main() {
	int H, W, d;
	cin >> H >> W >> d;

		int off = (d-1)/2 ;
		int cnt = d % 2 ? 1 : 2;
		int i = 0;
		while(cnt <= d) {
			rep(j,cnt) {
				p[i][off+j] = 2;
			}
			rep(j,cnt)
				p[i][off+j+d] = 3;
			cnt += 2;
			i++;
			off--;
		}
		cnt -= 2;
		off++;
		i--;
		while(cnt > 0) {
			cnt -= 2;
			off++;
			i++;
			if(cnt < 0) break;
			rep(j,cnt)
				p[i][off+j] = 2;
			rep(j,cnt)
				p[i][off+j+d] = 3;
		}

		rep(i,d) {
			rep(j,d*2) {
				if(!p[i][j]) {
					int t;
					t = (i < d/2) ? 1 : 0;
					if(j < d/2 || d+d/2 <= j) t = !t;
					p[i][j] = t;
				}
			}
		}

	string s = "RYGB";
	rep(i,H) {
		rep(j,W) {
			int a = 0;
			cout << s[p[i % d][j % (2*d)] ^ ((i / d) % 2)];
		}
		cout << endl;
	}
	return 0;
}
