#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;

int n, a[N], q[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int h = 1;

	int ba = 0;
	for (int i = 0; i < n; i++) {
		q[h]++;

		int em = a[i] - (i + 1);
		int t = (i + 1) - em;

		while (t - ba > 1) {
			h++;
			ba += 2;
		}
	}	
//	for (int i = 1; i <= n; i++) cout << q[i] << endl;
	int ans = 1;
	int s = 0;
	for (int i = 1; i <= n; i++) {
		s += q[i];
		ans = (ans * 1ll * s) % M;
		s--;
	}
	cout << ans << endl;
	return 0;
}