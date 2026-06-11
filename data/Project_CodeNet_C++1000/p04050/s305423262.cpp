#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	if(m == 1) {
		int t;
		cin >> t;
		if(t == 1) {
			cout << 1 << endl;
			cout << 1 << endl;
			cout << 1 << endl;
			return 0;
		}
		cout << t << endl;
		cout << 2 << endl;
		cout << t - 1 << " " << 1 << endl;
		return 0;
	}
	vi even, odd;
	for(int i=0;i<m;i++) {
		int t;
		cin >> t;
		if(t & 1) odd.PB(t);
		else even.PB(t);
	}
	if(odd.size() >= 3) {
		cout << "Impossible" << endl;
		return 0;
	}
	vi v;
	if(odd.size()) {
		v.PB(odd.back());
		odd.pop_back();
	}
	for(int i:even) v.PB(i);
	if(odd.size()) {
		v.PB(odd.back());
		odd.pop_back();
	}
	for(int i:v) cout << i << " ";
	cout << endl;
	v[0]++;
	v.back()--;
	if(v.back() == 0) v.pop_back();
	cout << v.size() << endl;
	for(int i:v) cout << i << " ";
	cout << endl;
}



