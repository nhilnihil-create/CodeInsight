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

bool ask(ll x){
	cout<<"? "<<x<<endl; cout<<flush;
	string s;
	cin>>s;
	return s[0]=='Y';
}

void res(ll x){
	cout<<"! "<<x<<endl;
}

int main(){
	ll s = 1e9, r = s-1;
	ll t = 0;
	rep(i, 9){
		t *= 10;
		ll lb = -1, ub = 9; // (lb, ub]
		while(ub-lb>1){
			ll md = (lb+ub+1)/2;
			ll x = (t+md)*s+r;
			if(ask(x)) ub = md;
			else lb = md;
		}
		if(i>0) t += ub;
		else t += max(ub, 1LL);
	}
	while(t%10==0) t /= 10;
	ll tt = t, t10 = t%10;
	rep(i, 10){
		if(t10!=9){
			if(ask(t+1)) break;
		} else {
			if(!ask(t-1)){
				t /= 10;
				break;
			}
		}
		t *= 10;
	}
	res(t);
	return 0;
}
