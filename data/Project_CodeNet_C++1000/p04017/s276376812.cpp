/*
https://open.spotify.com/track/1nEjpWJlqcOsf2ZaRQ3XdW?si=gmXBzPYtTPy6Mi9iqI9hvA

In the particularly cold night
Perhaps you couldn’t sleep well
In the bright morning woken up from sleep
You are full of darkness
You, who were so worried for some reason that you
Hugged me tightly and asked for my love

You broke and ruined my everything
My daily life and even my people yeah
I resent you all day
But to leave you I oh I

Don’t worry babe
I love you babe
I’ll be by your side
Maybe

Maybe

Looks about to collapse but remains
And the cycle continues unsteadily
I’m about to give up but when I see you I Oh I

No babe
I love you babe
I’ll hold your hand
Maybe

Maybe
I’ll be by your side
Maybe
I’ll trust you

Stay with me, stay with me
So you won’t think of anything
I’ll stay here pretending to be reluctant
So hold me back
Maybe

Maybe
I will be by your side
Maybe
I’ll trust you

Maybe

*/
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define for1(i, a, b) for(i = a; i <= b; ++i)
#define for0(i, a, b) for(i = a; i < b; ++i)
#define forw1(i, a, b) for(i = a; i >= b; --i)
#define forw0(i, a, b) for(i = a - 1; i >= b; --i)
#define fora(v, a) for(auto v : a)
#define bp __builtin_popcount
#define bpll __builtin_popcountll

using namespace std;
using cd = complex<double>;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<cd> vcd;
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;

const int modd1 = 1e9 + 7, modd2 = 998244353, maxn = 1e5+ 10, mxlog = 20, K = 26;
const double pi = acos(-1);
int n, q, l, nxt[mxlog][maxn];
vi x;

void solve(){
	int i, j, k, r;
	cin >> n ;
	for0(i, 0, n){
		int now; cin >> now; x.pb(now);
	}
	cin >> l;
	for0(i, 0, n){
		int val = upper_bound(x.begin(), x.end(), x[i] + l) - x.begin() - 1;
		nxt[0][i] = val;
	}
	for0(i, 1, 20){
		for0(j, 0, n){
			nxt[i][j] = nxt[i- 1][nxt[i - 1][j]];
		}
	}
	cin >> q;
	while(q--){
		int a, b; cin >> a >> b; a--; b--;
		if(a > b) swap(a, b);
		int ans = 0;
		forw0(i, mxlog, 0){
			if(nxt[i][a] < b){
				ans += (1 << i);
				a = nxt[i][a];
			}
		}
		cout << ans + 1 << '\n';
	}
}

signed main() {
    //freopen(".INP", "r", stdin);
    //freopen(".OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
