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
#define N 300000
#define M 100001
int n, m;
int x[N], x2[N];
int y[N];
int z[N];
int w[N], w2[N];
int main(){
	cin>>n>>m;
	rep(i, n) cin>>x[i];
	sort(x, x+n);
	rep(i, n) x2[x[i]]++;
	rep(i, M) w[i%m] += x2[i]/2;

	rep(i, n) y[x[i]%m]++;
	int res = 0;
	rep(i, m/2+1){
		if(i*2%m==0){
			z[i] = y[i]/2;
			res += z[i];
			z[i] *= 2;

		} else {
			z[i] = z[m-i] = min(y[i], y[m-i]);
			res += z[i];
		}
		//cerr<<i<<" "<<m-i<<" "<<z[i]<<endl;
	}
	//cerr<<res<<endl;
	rep(i, m){
		int t = min(w[i], (y[i]-z[i])/2);
		res += t;
		//cerr<<i<<" "<<t<<endl;
	}
	cout<<res<<endl;
	return 0;
}
