#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define mfill(x,y) memset(x,y,sizeof(x))
#define all(v) v.begin(), v.end()
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
using vint = vector<int>;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}

int n,m;ll w, h;
vector<ll> d(10, 0);
//vector<vector<bool>> f;
map<pair<ll, ll>,bool> f;

vint dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
vint dx8 = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8 = {-1, 0, 1, 1, 1, 0, -1, -1};

int cou(ll x, ll y){
	int c = 0;
	if(f[pair<ll,ll>(x,y)])c++;
	rep(i, 8){
		if(f[pair<ll,ll>(x+dx8[i],y+dy8[i])])c++;
	}
	return c;
}

int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	debug("debug test\n");
   	cin>>h>>w>>n;
	
	d[0] = (w-2)*(h-2);
	rep(i, n){
		ll a, b;
		cin>>a>>b;a--;b--;
		rep(j, 8){
			ll nx = a+(ll)dx8[j];
			ll ny = b+(ll)dy8[j];
			if(0 < nx && nx < h-1 && 0 < ny && ny < w-1){
				int c = cou(nx, ny);
				d[c]--;
				d[c+1]++;
				//debug("%d %d %d\n",nx,ny,c);
			}else{
				//debug("%d %d xx\n",nx,ny);
			}
		}
		if(0 < a && a < h-1 && 0 < b && b < w-1){
			int c = cou(a, b);
			d[c]--;
			d[c+1]++;
			//debug("%d %d %d\n",a,b,c);
		}

		f[pair<ll,ll>(a,b)] = true;
	}
	rep(i, 10){
		cout << d[i]<< endl;
	}
	return 0;
}
