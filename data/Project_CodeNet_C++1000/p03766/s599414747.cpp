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

#define ll long long
#define FOR(i,a) for(ll i=0;i<(ll)a.size();i++)
#define pb push_back
#define ld long double
#define mp make_pair
#define F first
#define S second
#define pii pair<ll,ll> 

using namespace :: std;

const ll maxn=1e6+100;
const ll mod=1e9+7;

ll f[maxn];
ll n;

inline ll find_dp(ll i){
	if(i>n){
		return 1;
	}
	return f[i];
}
inline ll ok(ll a){
	while(a<0)a+=mod;
	while(a>=mod)a-=mod;
	return a;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	f[n]=n;
	ll sum= n-1 ;
	for(ll i=n-1;i>=1;i--){
		// sum= i+3 i+4   ... i+n+1
		f[i]=ok((n-1)*(n-1)+sum+find_dp(i+1));
		sum+=find_dp(i+2)-find_dp(i+n+1);

		if(sum<0)sum+=mod;
		if(sum>=mod)sum-=mod;
   	}

	cout<<f[1];
}		
