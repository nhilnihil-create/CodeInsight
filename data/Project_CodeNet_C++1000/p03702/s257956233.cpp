#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
}*/

int n, a, b;
vi h;

bool check(int x)
{
	vi v;
	rep(i, 0, n) v.pb(max(0LL, h[i]-b*x));
	int cnt = 0;
	rep(i, 0, n){
		cnt += (v[i]+(a-b)-1)/(a-b);
	}
	return cnt <= x;
}

signed main()
{
	cin >> n >> a >> b;
	h.resize(n);
	rep(i, 0, n) cin >> h[i];

	int l = 0, r = 1e9;
	while(r-l > 1){
		int m = (l+r)/2;
		if(check(m)) r = m;
		else l = m;
	}
		
	cout << r << endl;

	return 0;
}
