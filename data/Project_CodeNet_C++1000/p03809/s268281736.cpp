#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
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
#pragma comment(linker, "/STACK:1024000000,1024000000") 
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define set0(x) memset((x),0,sizeof(x))
#define setINF(x) memset((x),63,sizeof(x))
using namespace std;
int n,a[100005],s;
vector<int> g[100005];
int dfs(int x,int p){
	int cnt=0,mx=0;
	for(int i=0;i<g[x].size();i++){
		int u=g[x][i];
		if(u==p)continue;
		int t=dfs(u,x);
		cnt+=t;
		mx=max(mx,t);
	}
	if(s==x)return a[x]-cnt;
	if(g[x].size()==1)return a[x];
	if(a[x]*2<cnt || mx>a[x] || a[x]>cnt){
		cout<<"NO\n";
		exit(0);
	}
	return a[x]*2-cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<n;i++){
		if(g[i].size()==1){
			if(dfs(s=i,-1))cout<<"NO\n";
			else cout<<"YES\n";
			break;
		}
	}
	return 0;
}