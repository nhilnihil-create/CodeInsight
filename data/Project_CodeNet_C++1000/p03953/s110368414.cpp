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


typedef vector<ll> vec;
typedef vector<vec> mat;

int main(){
	int n;
	cin>>n;
	vec x(n);
	rep(i, n) cin>>x[i];
	vec y(n+1);
	y[0] = x[0];
	rep(i, n) y[i+1] = x[i+1]-x[i];
	ll m, k;
	cin>>m>>k;
	vec f(n+1);
	rep(i, n+1) f[i] = i;
	vec g(f);
	rep(i, m){
		int a;
		cin>>a; a--;
		swap(f[a], f[a+1]);
	}
	while(k){
		if(k&1){
			rep(i, n+1) g[i] = f[g[i]];
		}
		vec f2(f);
		rep(i, n+1) f[i] = f2[f2[i]];
		k >>= 1;
	}
	vec y2(y);
	rep(i, n+1) y[i] = y2[g[i]];
	x[0] = y[0];
	rep(i, n) x[i+1] = y[i+1]+x[i];
	rep(i, n) cout<<x[i]<<endl;
	return 0;
}
