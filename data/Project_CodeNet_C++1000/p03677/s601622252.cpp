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
#define N 200010
ll d[N];
int main(){
	ll n, m;
	cin>>n>>m;
	vector<int> a(n);
	rep(i, n) cin>>a[i];
	ll res = 0;
	rep(i, n-1){
		int x = a[i], y = a[i+1];
		if(y<x) y += m;
		res += y-x;
		if(y-x<=1) continue;
		d[x+2] += 1;
		d[y+1] += -(y-x);
		d[y+2] += y-x-1;
	}
	rep(i, 2*m) d[i+1] += d[i];
	rep(i, 2*m) d[i+1] += d[i];
	ll mx = 0;
	rep(i, m) mx = max(mx, d[i+1]+d[i+1+m]);
	cout<<res-mx<<endl;
	return 0;
}