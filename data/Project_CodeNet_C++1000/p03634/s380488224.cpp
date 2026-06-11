#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
int n;
//vector<int> g[200020];
vector<pair<int,int>> g[200020];
ll s[200020];
bool used[200020];
void dfs(ll x,ll sum){
	used[x]=1;
	for(auto y:g[x]){
		if(used[y.first]) continue;
		s[y.first]+=(y.second+sum);
		dfs(y.first,s[y.first]);
	}
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N-1),B(N-1),ans(N-1,-1);
    for(ll i=0;i<N-1;i++){
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;
        
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
	ll Q,K;
	cin >> Q >>K;
	dfs(K-1,0);
	for(ll i=0; i<Q; i++){
		int aa,bb;
		cin >> aa >> bb;
		cout<<s[aa-1]+s[bb-1]<<" " << '\n';
	}
	return 0;
}
