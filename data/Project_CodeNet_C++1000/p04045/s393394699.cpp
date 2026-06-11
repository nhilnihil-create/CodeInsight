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
	int n, k;
	cin >> n >> k;
	vector<int> rec(10);
	rep(i, k) {
		int d;
		cin >> d;
		rec[d] = 1;
	}
	while (1) {
		bool elf = true;
		int now = n;
		while (now) {
			if (rec[now % 10]) elf = false;
			now /= 10;
		}
		if (elf) {
			cout << n << endl;
			return 0;
		}
		n++;
		
	}
	return 0;
}