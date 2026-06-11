#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	int res_2 = 0, res_4 = 0;
	rep(i, n) {
		if (a[i] % 4 == 0) {
			res_4++;
			continue;
		}
		if (a[i] % 2 == 0) res_2++;
	}

	vector<ll> jud(n, 1);
	if (res_4 >= 1) {
		jud[1] = 4;
		if (res_4 >= 2) {
			jud[n - 2] = 4;
			res_4--;
		}
		res_4--;
	}
	//4の配布
	rrep(i, n) {
		if (res_4 == 0) break;
		if (jud[i - 1] * jud[i] % 4 != 0) {
			jud[i] = 4;
			res_4--;
		}
	}
	bool elf = true;
	//2の配布
	rrep(i, n) {
		if (res_2 == 0) break;
		if (jud[i - 1] * jud[i] % 4 != 0) {
			if (jud[i - 1] % 2 != 0 && jud[i] % 2 != 0) {
				jud[i - 1] = 2;
				jud[i] = 2;
				res_2 -= 2;
			}
			else {
				if (jud[i] % 2 == 0) jud[i - 1] = 2;
				else jud[i] = 2;
				res_2--;
			}
		}
		if (res_2 < 0) {
			puts("No");
			return 0;
		}
	}
	rrep(i, n) {
		if (jud[i - 1] * jud[i] % 4 != 0) elf = false;
	}

	puts(elf ? "Yes" : "No");

	return 0;
}
