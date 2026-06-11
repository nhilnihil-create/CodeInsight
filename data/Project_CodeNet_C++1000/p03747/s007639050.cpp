#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <utility>
#include <memory>
#include <functional>
#include <deque>
#include <cctype>
#include <ctime>
#include <numeric>
#include <list>
#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <forward_list>

#define cauto const auto&
#else

#endif

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll;
typedef vector<vector<long long> > vvll;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}

#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _rep(i,n) _rep2((i),0,(n))
#define _rep2(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) GET_MACRO(__VA_ARGS__, _rep2, _rep)(__VA_ARGS__)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define fi first
#define se second
#define mkp make_pair
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif

#define MOD 1000000007LL
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)

void mainmain(){
	int n;
	cin>>n;
	ll L;
	cin>>L;
	ll T;
	cin>>T;
	vll a,b;
	vector<pll> in(n);
	ll cnt = -1;
	rep(i,n){
		ll x,w;
		cin>>x>>w;
		in[i] = pll(x, w);
		if(w==1){
			if(cnt<0) cnt = i;
			a.PB(x);
		}
		else{
			b.PB(x);
		}
	}
	if(b.size()==0 || a.size()==0){
		rep(i,n){
			ll tmp = in[i].fi;
			if(in[i].se==1){
				tmp += T%L;
				tmp %= L;
			}
			else{
				tmp -= T%L - L;
				tmp %= L;
			}
			cout<<tmp<<endl;
		}
		return;
	}
	for(ll x: b){
		cnt += 2*T/L;
		ll d;
		if(x>a[0]){
			d = x-a[0];
		}
		else{
			d = L-a[0] + x;
		}
		// cout<<d<<endl;
		if(d <= 2*T%L){
			cnt++;
		}
	}
	// cout<<cnt<<endl;
	cnt %= n;
	vll pos(n);
	ll p;
	rep(i,n){
		ll tmp = in[i].fi;
		if(in[i].se==1){
			tmp += T%L;
			tmp %= L;
		}
		else{
			tmp -= T%L - L;
			tmp %= L;
		}
		if(in[i].fi == a[0] && in[i].se == 1) p = tmp;
		pos[i]=tmp;
	}
	sort(ALL(pos));
	vll ans(n);
	for(int i=n-1; i>=0; i--){
		if(pos[i] == p){
			rep(j,n){
				int ind = (cnt+j)%n;
				ans[ind] = pos[(i+j)%n];
			}
			break;
		}
	}
	rep(i,n){
		cout<<ans[i]<<endl;
	}
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}