#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(X,Y) ((X)>(Y)?X=(Y),true:false)
#define chmax(X,Y) ((X)<(Y)?X=(Y),true:false)
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}
#define N 100010
ll x[N], w[N], y[N], r[N];
int main(){
	ll n, l, t;
	cin>>n>>l>>t;
	rep(i, n){
		cin>>x[i]>>w[i];
		w[i] = w[i]==1?1:-1;
		y[i] = (x[i]+w[i]*t)%l;
		if(y[i]<0) y[i] += l;
	}
	ll sw = 0, w0 = w[0];
	if(w[0]<0){
		rep(i, n) w[i] *= -1;
		rep(i, n) x[i] *= -1;
	}
	bool just = false;
	rep(i, n){
		if(w[i]>0) continue;
		ll a = x[0]-x[i], b = x[0]-x[i]+2*t;
		cerr<<i<<" "<<a<<" "<<b<<endl;
		if(a<0) sw++;
		sw += b/l;
		if(b%l==0) just = true;
	}
	ll left = 0;
	if(w0<0){
		rep(i, n) w[i] *= -1;
		rep(i, n) x[i] *= -1;
		sw *= -1;
		sw %= n;
		if(sw<0) sw += n;
		left = !left;
	}
	sort(y, y+n);
	int p = -1;
	for(int i = 0; i < n; i++){
		if((x[0]+t*w[0]-y[i])%l==0){
			p = i;
			if(just && !left) p++;
			break;
		}
	}
	//cerr<<just<<" "<<left<<endl;
	//cerr<<sw<<" "<<p<<endl;
	rep(i, n) r[(i+sw)%n] = y[(p+i)%n];
	rep(i, n) cout<<r[i]<<endl;
	return 0;
}
