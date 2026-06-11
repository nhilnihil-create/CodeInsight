#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, n) for(int i = s; i < n; ++i)
#define rep(i, n)		 REP(i, 0, n)
#define SORT(c)			 sort((c).begin(), (c).end())
#define IINF	INT_MAX
#define LLINF LLONG_MAX

typedef long long				ll;
typedef pair <int, int> ii;

#define DEBUG false

int main() {
		ll n, m;
		cin >> n >> m;
		vector <ll>	 cnt(m);
		vector <ll>	 cnt2(m);
		map <ll, ll> mp;
		rep(i, n) {
				ll tmp;
				cin >> tmp;
				cnt[(ll) (tmp % m)]++;
				mp[tmp]++;
				if(mp[tmp] == 2) {
						mp[tmp] = 0;
						cnt2[(ll) (tmp % m)]++;
				}
		}

		ll ans = 0;

		ans += (ll) (cnt[0] / 2);
		if(DEBUG) cout << "ans0:" << ans << endl;
		REP(i, 1, (int) ((m + 1) / 2)) {
      if(DEBUG) cout << "i:"<<i<<endl;
				if(cnt[i] > cnt[m - i]) {
						ll p = cnt[m - i];
						ans += p;
            if(DEBUG) cout << "p:" <<p<<endl;
						if(cnt2[i] > 0 && cnt[i] - p >= 2) ans += min((ll) ((cnt[i] - p) / 2), cnt2[i]);
            if(DEBUG) cout << (ll) ((cnt[i] - p) / 2)<<endl;
						if(DEBUG) cout << "ans1:" << ans << endl;
				}
				else {
						ll p = cnt[i];
						ans += p;
						if(cnt2[m - i] > 0 && cnt[m - i] - p >= 2) ans += min((ll) ((cnt[m - i] - p) / 2), cnt2[m-i]);
						if(DEBUG) cout << "ans2:" << ans << endl;
				}
		}

		if(DEBUG) cout << "ans3:" << ans << endl;
		if(m % 2 == 0) ans += (ll) (cnt[(int) (m / 2)] / 2);
		if(DEBUG) cout << "ans4:" << ans << endl;

		cout << ans << endl;

		return 0;
}
