#include<bits/stdc++.h>
using namespace std;
const bool DBG = 1;

#define TRACE(x)    x
#define WATCH(x)    TRACE(cout << #x" = " << x << endl)
#define WATCHR(a,b) TRACE(for(auto it=a; it!=b;) cout<<*(it++)<<" ";cout<<endl)
#define WATCHC(V)   TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pair<int,int>> vpii;

const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int N, a;
	cin >> N;
	ll r = 1;
	int p = 1;
	ll ctr = N;
	ll cp = 0;
	for(ll i = 1; i <= N; i++) {
		cin >> a;
		if(a < p) {
			ctr--;
			r *= (i-cp);
			cp++;
			r %= MOD;
			//p -= 1;
		} else {
			p += 2;
		}
		//cout << i << " " << a << " " << p << " " << r << " " << p << endl;
	}
	for(ctr; ctr > 0; ctr--) {
		r *= ctr;
		r %= MOD;
	}

	cout << r << endl;

	return 0;
}
