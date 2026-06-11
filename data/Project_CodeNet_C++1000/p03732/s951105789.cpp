#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)
#define allof(v) (v).begin(), (v).end()


#define MOD 1000000007

li n, w;
li ww[111];
li v[111];

vector<vector<li>> ws__;

li cumuls[4][111];

int main(void)
{
	cin >> n >> w;
	ws__.resize(4);

	rep(i, n) {
		cin >> ww[i] >> v[i];
	}
	li base = ww[0];

	rep(i, n) {
		ws__[ww[i] - base].push_back(v[i]);
	}

	rep(i, 4) {
		sort(ws__[i].begin(), ws__[i].end());
		reverse(ws__[i].begin(), ws__[i].end());
		cumuls[i][0] = 0;
		rep(j, ws__[i].size()) {
			cumuls[i][j + 1] = cumuls[i][j] + ws__[i][j];
		}
	}

	li res = 0;
	rep(i1, ws__[0].size() + 1) {
		if (base * i1 > w) {
			break;
		}
		rep(i2, ws__[1].size() + 1) {
			if (base * i1 + (base + 1) * i2 > w) {
				break;
			}
			rep(i3, ws__[2].size() + 1) {
				if (base * i1 + (base + 1) * i2 + (base + 2) * i3 > w) {
					break;
				}
				rep(i4, ws__[3].size() + 1) {
					if (base * i1 + (base + 1) * i2 + (base + 2) * i3 + (base + 3) * i4 > w) {
						break;
					}
					res = max(res, cumuls[0][i1] + cumuls[1][i2] + cumuls[2][i3] + cumuls[3][i4]);
				}
			}
		}
	}
	cout << res << endl;




	return 0;
}