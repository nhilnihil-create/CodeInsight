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

vector<ll> zoj;
vector<ll> fard;
vector<ll> a;
void pri(vector<ll> anss){
	for(auto e:a){
		cout<<e<<' ';
	}	
	vector<ll> ans;
	for(auto e:anss)if(e)ans.pb(e);
	cout<<endl<<ans.size()<<endl;
	for(auto e:ans){
		cout<<e<<' ';
	}
	exit(0);
}
void add(vector<ll> &ans,ll a){
	ll b=a/2;
	if(b%2==0){
		ans.pb(a);
	}else{
		
	}
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		ll a;
		cin>>a;
		if(a%2==1){
			fard.pb(a);
		}else{
			zoj.pb(a);
		}
	}
	vector<ll> ans;
	if(fard.size()==0){
		a=zoj;
	}
	if(fard.size()==1){
		a.pb(fard[0]);
		for(auto e:zoj){
			a.pb(e);
		}
	}
	if(fard.size()<=1){
		ans.pb(a[0]-1);
		for(ll i=1;i<a.size();i++){
			ans.pb(a[i]);
		}
		ans.pb(1);
		pri(ans);
	}
	if(fard.size()==2){
		a.pb(fard[0]);
		for(auto e:zoj){
			a.pb(e);
		}
		a.pb(fard[1]);

		ans.pb(a[0]-1);
		for(ll i=1;i+1<a.size();i++){
			ans.pb(a[i]);
		}
		ans.pb(2);
		ans.pb(a.back()-1);
		pri(ans);
	}
	cout<<"Impossible";
}


















