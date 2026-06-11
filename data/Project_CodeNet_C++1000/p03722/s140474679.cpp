#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e4;

const ll inf = 1e18;

int n, m;
ll a[maxn], b[maxn], c[maxn];
ll dist[maxn];

void relax(ll& x, ll y) {
    x=max(x,y);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
	cin>>a[i]>>b[i]>>c[i];
    }

    ll best = -inf;

    for (int i=1; i<=n; i++) {
	dist[i] = -inf;
    }

    dist[1] = 0;


    for (int iter=0; iter<n+10; iter++) {
	for (int i=0; i<m; i++) {
	    int from=a[i]; int to=b[i]; ll wei = c[i];
	    if (dist[from] > -inf) {
		relax(dist[to], dist[from]+wei);
	    }
	}
	best=max(best, dist[n]);
    }


    {
	ll prev=dist[n];
	for (int i=0; i<m; i++) {
	    int from=a[i]; int to=b[i]; ll wei = c[i];
	    if (dist[from] > -inf) {
		relax(dist[to], dist[from]+wei);
	    }
	}
	if (dist[n]>prev) out("inf");
    }


    out(best);
  

    return 0;
}
