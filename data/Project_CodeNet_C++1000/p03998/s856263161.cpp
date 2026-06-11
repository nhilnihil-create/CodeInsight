#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b, c;
	cin >> a >> b >> c;
	int pos_a = 0, pos_b = 0, pos_c = 0, turn = 0;
	while(1) {
		if (turn == 0) {
			if (pos_a == a.size()) {
				cout << "A" << endl;
				return 0;
			}
			turn = int(a[pos_a] - 'a');
			pos_a++;
		}
		else if (turn == 1) {
			if (pos_b == b.size()) {
				cout << "B" << endl;
				return 0;
			}
			turn = int(b[pos_b] - 'a');
			pos_b++;
		}
		else {
			if (pos_c == c.size()) {
				cout << "C" << endl;
				return 0;
			}
			turn = int(c[pos_c] - 'a');
			pos_c++;
		}
	}
	return 0;
}
