#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> P;
 
const int INF = 1e9;
//const ll INF = 1e18;
const double EPS = 1e-10;
const int MOD = 1e9+7;
const double PI = acos(-1.0);

int main()
{
	vi a(7);
	rep(i,7) cin >> a[i];
	ll ans[4] = {},mi = min({a[0],a[3],a[4]});
	ans[0] = a[0]/2*2+a[3]/2*2+a[4]/2*2;
	a[0] -= mi,a[3] -= mi,a[4] -= mi;
	ans[1] = mi*3+a[0]/2*2+a[3]/2*2+a[4]/2*2;
	if(mi){
		mi--,a[0]++,a[3]++,a[4]++;
		ans[2] = mi*3+a[0]/2*2+a[3]/2*2+a[4]/2*2;
	}
	
	cout << a[1] + max({ans[0],ans[1],ans[2],ans[3]}) << endl;
	return 0;
}