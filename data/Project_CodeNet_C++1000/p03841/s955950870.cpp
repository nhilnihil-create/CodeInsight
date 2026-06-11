#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

#define ll int
#define pb push_back
#define ld long double
#define mp make_pair
#define F first
#define S second
#define pii pair<ll,ll> 

using namespace :: std;

const ll maxn=520;
const ll maxm=500*510;

ll x[maxn];
set<ll> st;
ll ans[maxm];
pii y[maxn];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>x[i];
		y[i]=mp(x[i],i);
		ans[x[i]]=i;
	}
	sort(y+1,y+n+1);
	ll m=(n*n);
	for(ll i=1;i<=m;i++){
		if(ans[i]==0){
			st.insert(i);
		}
	}
	for(ll i=1;i<=n;i++){
		ll v=y[i].S;
		for(ll j=1;j<v;j++){
			ll e=(*st.begin());
			st.erase(e);
			if(e>y[i].F){
				cout<<"No";
				return 0;
			}
			ans[e]=v;
		}
	}
	for(ll i=n;i>=1;i--){
		ll v=y[i].S;
		for(ll j=1;j<=n-v;j++){
			ll e=(*st.rbegin());
			st.erase(e);
			if(e<y[i].F){
				cout<<"No";
				return 0;
			}
			ans[e]=v;
		}
	}
	

	cout<<"Yes\n";
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}


















