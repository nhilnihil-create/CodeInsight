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
	int n;
	cin>>n;
	vector<P> x(n);
	vector<int> r(n*n, -1);
	bool ok = true;
	rep(i, n){
		int t;
		cin>>t;
		x[i] = P(t-1, i);
		if(r[t-1]!=-1) ok = false;
		r[t-1] = i;
	}
	sort(all(x));
	int p = 0;
	rep(i, n){
		int c = x[i].snd;
		while(c--){
			while(r[p]!=-1) p++;
			r[p] = x[i].snd;
		}
		if(p>x[i].fst) ok = false;
	}
	//rep(i, n*n) cerr<<r[i]<<endl;
	p = n*n-1;
	for(int i = n-1; i >= 0; i--){
		int c = n-x[i].snd-1;
		while(c--){
			while(r[p]!=-1) p--;
			r[p] = x[i].snd;
		}
		if(p<x[i].fst) ok = false;
	}
	if(!ok) cout<<"No"<<endl;
	else {
		cout<<"Yes"<<endl;
		rep(i, n*n) cout<<r[i]+1<<" ";
		cout<<endl;
	}
	return 0;
}
