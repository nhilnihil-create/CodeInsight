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

long long max(long long x, long long y){return (x > y ? x : y);}
long long min(long long x, long long y){return (x < y ? x : y);}

#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define F first
#define S second
#define pii pair<ll,ll> 

using namespace :: std;

const ll maxn=3e5+500;
const ll inf=1e17+7;

ll A[maxn];
vector<ll> in[maxn];
ll ans=0,k;

ll dfs(ll a){
	ll mx=0;
	for(ll i=0;i<in[a].size();i++){
		ll v=in[a][i];
		mx=max(mx,dfs(v)+1);
	}
	if(mx>=k-1 && A[a]!=1){
		ans++;
		return -1;
	}
	return mx;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	ll n;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>A[i];
	}
	if(A[1]!=1){
		ans++;
		A[1]=1;
	}
	for(ll i=2;i<=n;i++){
		in[A[i]].pb(i);
	}
	dfs(1);
	cout<<ans;
}

















