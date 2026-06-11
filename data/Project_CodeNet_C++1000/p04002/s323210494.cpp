#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include<vector>
#include<cstdlib>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
const ll MOD = 1e9 + 7;
#define rep(i,k) for(int i=0;i<k;i++)
ll n, i, j, k, o, p, l, z,x,y,h,w,sa=0;
ll a[200010], b[200010], inf = 1000000000000;
map <ll, ll> cnt;
l_l pp;
string s;
vector<pair<ll, ll>> m;

int main() {
	cin >> h>>w>>n;
	z = 0;
	if (n == 0) {
		cout << (h - 2) * (w - 2)<<"\n";
		rep(i, 9)cout << 0 << "\n";

		return 0;
	}
	rep(i, n) {
		cin >> o >> p;
		rep(j, 3) {
			ll gg = p - 1 + j;
			rep(k, 3) {
				ll rr = o - 1 + k;
				if ((rr > 1 && rr < h) && (gg > 1 && gg < w)) {
				//	cout << " " << rr << " " << gg << "\n";
					pp = make_pair(rr, gg);
					m.push_back(pp);
				}
			}
		}
	}
	sort(m.begin(), m.end());
	pp = m[0]; z = 1;
	for (i = 1; i < m.size();i++) {
		if (pp == m[i])z++;	
		else {
			a[z]++;
			sa++;
			z = 1;
		}
		pp = m[i];
	}
	a[z]++;
	sa++;


	cout << ((h-2)*(w-2)-sa)<<"\n";
	rep(i, 9)cout << a[i + 1]<<"\n";
	


	
}