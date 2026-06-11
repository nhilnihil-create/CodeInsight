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
#define chmin(x,y) (x=min(x,y))
#define chmax(x,y) (x=max(x,y))
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}

int main(){
	int n, m;
	cin>>n>>m;
	vector<int> a(m);
	rep(i, m) cin>>a[i];
	sort(all(a), [](int x, int y){return x%2>y%2;});
	if(m>2) swap(a[1], a[m-1]);
	if(m>2 && a[2]%2==1){
		cout<<"Impossible"<<endl;
		return 0;
	}
	vector<int> b;
	rep(i, m){
		int t = a[i];
		if(i==0) t++;
		if(i==m-1) t--;
		if(t) b.pb(t);
	}
	if(a.size()==1 && a[0]>1){
		b[0]--;
		b.pb(1);
	}
	cout<<a<<endl;
	cout<<b.size()<<endl;
	cout<<b<<endl;

	return 0;
}
