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
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

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

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()
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

// Mod int
// const int MOD = 1000000007;
struct mint{
    ll x;
    mint():x(0){}
    mint(ll x):x((x%MOD+MOD)%MOD){}
    mint operator+=(const mint& a){ if((x+=a.x)>=MOD) x-=MOD; return *this;}
    mint operator-=(const mint& a){ if((x+=MOD-a.x)>=MOD) x-=MOD; return *this;}
    mint operator*=(const mint& a){ (x*=a.x)%=MOD; return *this;}
    mint operator+(const mint& a)const{ return mint(*this) += a;}
    mint operator-(const mint& a)const{ return mint(*this) -= a;}
    mint operator*(const mint& a)const{ return mint(*this) *= a;}
    bool operator==(const mint& a)const{ return x == a.x;}
    friend ostream& operator<<(ostream& os, const mint& mi)  
    {  
        os << mi.x;  
        return os;  
    }
};

void mainmain(){
	int n;
	cin>>n;
	// assert(n<=8);
	vll v(n);
	rep(i,n) cin>>v[i];
	mint ans(1);
	v[0] = 1;
	reep(i,1,n){
		if(v[i-1]+1==v[i]) continue;
		v[i] = v[i-1] + 2;
	}
	// rep(i,n){
	// 	cout<<v[i]<<" ";
	// }cout<<endl;
	mint can(0);
	vll a;
	int cnt = 1;
	rep(i,n-1){
		if(v[i]+1==v[i+1]){
			cnt++;
		}
		else{
			a.PB(cnt);
			cnt = 1;
		}
	}
	a.PB(cnt);
	int p = 0;
	int aki = 0;
	// rep(i,a.size()) cout<<a[i]<<endl;
	while(p<a.size()){
		if(a[p]==1){
			can+=mint(1);
			p++;
		}
		else if(aki){
			a[p]--;
			can+=mint(1);
			aki--;
		}
		else if(a[p]==2){
			ans*=can+mint(2);
			can+=mint(1);
			aki++;
			p++;
		}
		else{
			ans*=can+mint(2);
			can+=mint(1);
			a[p]-=2;
		}
	}
	while(can.x){
		ans*=can;
		can-=mint(1);
	}
	cout<<ans<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}