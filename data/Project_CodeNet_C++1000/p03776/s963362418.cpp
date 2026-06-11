#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

ll C[55][55];

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<ll> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(all(v));
	reverse(all(v));
	
	int cnt = 1;
	ll avg = v[0];
	for(int i = 1; i < a; i++) {
		avg += v[i];
		if(v[i] != v[i - 1]) cnt = 0;
		cnt++;
	}
	
	int nums = 0;
	for(int i = 0; i < n; i++) {
		if(v[a - 1] == v[i]) nums++;
	}
	
	ll ans = 0;
	if(v[a - 1] == v[0]) for(int i = min(b, nums); i >= a; i--) {
//		cout << C(nums, i) << endl;
		ans += C[nums][i];
	} else ans = C[nums][cnt];
	
	cout << fixed << setprecision(6);
	cout << (long double) avg / a << endl << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	C[0][0] = 1;
	for(int i = 1; i <= 50; i++) {
    	C[i][0] = C[i][i] = 1;
    	for(int j = 1; j < i; j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
	}
	
	solve();
    return 0;
}