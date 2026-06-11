#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define mfill(x,y) memset(x,y,sizeof(x))
#define all(v) v.begin(), v.end()
#define in(x,y,h,w) if(0<=x&&x<h&&0<=y&&y<w)
#define y0 y12345
#define y1 y54321

#ifdef LOCAL
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ul = unsigned long;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;using vvint = vector<vector<int>>;
using vll = vector<ll>;using vvll = vector<vector<ll>>;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}
template <class T>void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}
template <class T>T gcd(T &a, T &b){if(a<b){swap(a,b);} T r = a%b; while(r!=0){a=b;b=r;r=a%b;} return b;}

vint dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
vint dx8 = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8 = {-1, 0, 1, 1, 1, 0, -1, -1};

int n;
vint a, b, c;
int ma, mb;
int inf = 1000000;
vector<vector<vint>> d;

int dp(int pos, int na, int nb){
	if(pos == n){
		if(na > 0 && (double)na/ma == (double)nb/mb){
			return 0;
		}else{
			return inf;
		}
	}
	if(d[pos][na][nb]!=2*inf)return d[pos][na][nb];
	int ret = inf;
	chmin(ret, c[pos]+dp(pos+1, na+a[pos], nb+b[pos]));
	chmin(ret, dp(pos+1, na, nb));
	return d[pos][na][nb]=ret;
}

int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	debug("debug test\n");
	cin>>n>>ma>>mb;
	a = vint(n);
	b = vint(n);
	c = vint(n);
	//d.assign(n, vector<vint>(n*10+1, vint(n*10+1, inf)));
	d = vector<vector<vint>>(n, vector<vint>(n*10+1, vint(n*10+1, 2*inf)));
	rep(i, n){
		cin>>a[i]>>b[i]>>c[i];
	}
	int ans = dp(0, 0, 0);

	if(ans < inf)cout << dp(0, 0, 0) << endl;
	else cout << -1 << endl;

	return 0;
}
