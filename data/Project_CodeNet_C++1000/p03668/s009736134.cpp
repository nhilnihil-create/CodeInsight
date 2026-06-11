//作者：中国江苏省南京市李硕睿
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
typedef long long ll;
const int N=1e5+7;
vector<int> adj[N];
int mark[N];
int nim[N];
void dfs(int v,int p){
	for (auto u:adj[v])
		if (u!=p){
			dfs(u,v);
			nim[v]^=nim[u]+1;
		}
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for (int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		u--; 
		v--;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	dfs(0,-1);
	cout<<(nim[0] ? "Alice" : "Bob")<<"\n";
	return 0;
}