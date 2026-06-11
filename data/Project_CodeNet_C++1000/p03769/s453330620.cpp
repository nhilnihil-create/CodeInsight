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

int main(){
	ll n;
	cin>>n;
	n++;
	ll i = 1;
	while(i<=n) i<<=1;
	i >>= 2;
	vector<int> res1, res2;
	//r.push_back(1);
	//r.push_back(1);
	int c = 1;
	while(i){
		if(true){
			res1.push_back(c);
			res2.push_back(c);
			c++;
		}
		if(n&i){
			res1.push_back(c);
			res2.insert(res2.begin(), c);
			c++;
		}
		i>>=1;

	}
	res1.insert(res1.end(), res2.begin(), res2.end());
	cout<<res1.size()<<endl;
	for(auto x: res1) cout<<x<<" "; cout<<endl;
	return 0;
}
