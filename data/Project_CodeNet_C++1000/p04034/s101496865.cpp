#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0)
#define sz(a) (a).size()


using namespace std;

const ll N = 1e5 + 120;
const ll big = 1e18;
const ll M = 2020;
const ll mod = 998244353;

ll n, m;

vector<ll> g[N];

ll cnt[N];

bool red[N];

int main() {
    speed;
	cin >> n >> m;
	red[1] = 1;
	for(int i = 1; i <= n; i++)
		cnt[i]++;
	while(m--) {
		ll a, b;
		cin >> a >> b;
		if(red[a]) {
			red[b] = 1;
			cnt[b]++;
			cnt[a]--;
			if(!cnt[a])
				red[a] = 0;
		}
		else
			cnt[b]++, cnt[a]--;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		ans += red[i];
	cout << ans;
}

/*
*/

