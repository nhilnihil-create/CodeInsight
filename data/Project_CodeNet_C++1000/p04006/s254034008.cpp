#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

#define prev(i) (i - 1 + n) % n

int main() {
	fastio;
	
    int n, x; cin >> n >> x;
    vi a(n); forn(i, n) cin >> a[i]; 

    ll mn_cost = 0; forn(i, n) mn_cost += a[i];

    forsn(k, 1, n) {
        ll cost = (ll) k * x;

        forn(i, n) cost += min(a[i], a[prev(i)]); 

        mn_cost = min(mn_cost, cost);

        vi b(n); forn(i, n) b[i] = min(a[i], a[prev(i)]);
        a = b;
    }

    cout << mn_cost << endl;
	
	return 0;
}
