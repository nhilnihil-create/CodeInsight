#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N; ll W; cin >> N >> W;
	vector<ll> w(N, 0LL), v(N, 0LL);
	set<ll> wk; wk.clear();
	rep (i, N){
		cin >> w[i] >> v[i];
		wk.insert(w[i]);
	} // end rep

	map<ll,int> w2i; w2i.clear();
	ll i2w[4] = {0LL};
	set<ll>::iterator it = wk.begin();
	for (int i = 0; it != wk.end(); ++it, ++i){
		int a = (*it);
		w2i[a] = i;
		i2w[i] = a;
	} // end for

	vector<ll> vk[4]; rep (i, 4) vk[i].clear();
	rep (i, N){
		vk[w2i[w[i]]].push_back(v[i]);
	} // end rep

	rep (i, 4){
		sort(ALL(vk[i]), greater<ll>());
	} // end rep

	ll res = 0LL;
	rep (i, (int)vk[0].size() + 1){
		rep (j, (int)vk[1].size() + 1){
			rep (k, (int)vk[2].size() + 1){
				rep (l, (int)vk[3].size() + 1){
					ll currW = (ll)i * i2w[0] + (ll)j * i2w[1] + (ll)k * i2w[2] + (ll)l * i2w[3];
					if (currW > W) continue;
					ll curr = 0LL;
					rep (i2, i){
						curr += vk[0][i2];
					} // end rep
					rep (j2, j){
						curr += vk[1][j2];
					} // end rep
					rep (k2, k){
						curr += vk[2][k2];
					} // end rep
					rep (l2, l){
						curr += vk[3][l2];
					} // end rep
					res = max(res, curr);
				} // end rep
			} // end rep
		} // end rep
	} // end rep

	cout << res << endl;
	
	return 0;
}