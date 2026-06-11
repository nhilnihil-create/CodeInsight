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
//#include <utility>
//#include <memory>
//#include <functional>
//#include <deque>
//#include <cctype>
//#include <ctime>
//#include <numeric>
//#include <list>
//#include <iomanip>

//#if __cplusplus >= 201103L
//#include <array>
//#include <tuple>
//#include <initializer_list>
//#include <forward_list>
//
//#define cauto const auto&
//#else

//#endif

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

void mainmain(){
	int n;
	scanf("%d", &n);
	// cout<<n<<endl;
	vll v(n);
	vint op(n);
	op[0]=1;
	int cnt = 0;
	rep(i,n){
		if(i){
			char t;
			scanf(" %c %lld", &t, &v[i]);
			if(t=='+') op[i]=1;
			else op[i]=-1,cnt++;
		}
		else{
			scanf("%lld", &v[i]);
		}
	}
	if(cnt<=1){
		ll sum = 0;
		rep(i,n){
			sum+=op[i]*v[i];
		}
		cout<<sum<<endl;
		return;
	}
	vll s(n+1);
	for(int i=n-1;i>=0;i--){
		if(i==n-1) s[i]=v[i];
		else{
			s[i]=s[i+1]+v[i];
		}
	}
	ll ans = -INFL;
	ll sum = 0;
	rep(i,n){
		sum+=op[i]*v[i];
	}
	ans=sum;
	sum=0;
	rep(i,n){
		if(op[i]==-1){
			ll t = v[i];
			int p = i;
			p++;
			while(p<n&&op[p]==1){
				t+=v[p];
				p++;
			}
			if(p==n){
				break;
			}
			maxs(ans, sum+(-t+s[p]));
			sum-=v[i];
		}
		else{
			sum+=v[i];
		}
	}
	cout<<ans<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}