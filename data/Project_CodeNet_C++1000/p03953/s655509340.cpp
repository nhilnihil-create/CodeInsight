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

#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define F first
#define S second
#define pii pair<ll,ll> 

using namespace :: std;

const ll maxn=1e5+500;
const ll inf=1e9+800;
const ll mod=1e9+7;

ll x[maxn];

ll b[maxn];
ll c[maxn];

ll a[maxn];
ll p[maxn];
ll ans[maxn];
bool vis[maxn];
vector<ll> vec;

void dfs(ll a){
	vis[a]=1;
	vec.pb(a);
	if(vis[p[a]])return ;
	dfs(p[a]);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>x[i];
	}
	ll m,k,firs;
	firs=x[1];
	cin>>m>>k;
	for(ll i=0;i<m;i++){
		cin>>a[i];
	}
	for(ll i=1;i<n;i++){
		b[i]=x[i+1]-x[i];
		p[i]=i;
	}

	for(ll i=0;i<m;i++){
		swap(p[a[i]],p[a[i]-1]);
	}
	for(ll i=1;i<n;i++){
		if(!vis[i]){
			vec.clear();
			dfs(i);
			ll m=vec.size();
			for(ll j=0;j<m;j++){
				c[vec[j]]=b[vec[(j+k)%m]];
			}
		}
	}

	ans[1]=firs;
	for(ll i=2;i<=n;i++){
		ans[i]=ans[i-1]+c[i-1];
	}
	for(ll i=1;i<=n;i++){
		cout<<ans[i]<<'\n';
	}
}


















