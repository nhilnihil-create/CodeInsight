#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define pp pop_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef long long ll;

using namespace std;

const int N = 3e5 + 111, inf = 1e9, mod = 1e9 + 7;
const double pi = acos(-1.0), eps = 1e-9;
const ll INF = 1e18;

int n, m, x;
vector <int> a, b, even, odd, nb;

int main(){
	srand(time(NULL));
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cout << setprecision(10) << fixed;

	cin >> n >> m;

	for(int i = 1; i <= m; ++i){
		cin >> x;
		if(x % 2 == 1)
			odd.pb(x);
		else even.pb(x);
	}

	if(sz(odd) > 2){
		cout << "Impossible";
		return 0;
	}

	if(sz(odd))
		a.pb(odd[0]);

	for(int i = 0; i < sz(even); ++i)
		a.pb(even[i]);

	if(sz(odd) == 2)
		a.pb(odd[1]);
	
	vector <int> b;
	for(int i = 0; i < m; ++i)
		b.pb(a[i]);

	b[0]--;	

	if(sz(a) == 1){
		b.pb(0);
	}

	b[sz(b) - 1] += 1;
	for(int i = 0; i < sz(b); ++i)
		if(b[i])
			nb.pb(b[i]);

	b = nb;

	for(int i = 0; i < m; ++i)
		cout << a[i] << " ";
	cout << endl << sz(b) << endl;

	for(int i = 0; i < sz(b); ++i)
		cout << b[i] << " ";
	
	//cout << (clock() + 0.0) / CLOCKS_PER_SEC;
	return 0;
}