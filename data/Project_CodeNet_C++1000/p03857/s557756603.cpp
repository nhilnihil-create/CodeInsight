#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <bitset>
#include <iterator>	
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cassert>
#define INF 2000000000000000
#define MOD 1000000007
#define sym cout<<"---------"<<endl;
#define ll long long
#define mk make_pair
#define en endl
#define RE return 0
#define int ll
#define P pair<int,int>
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int gcd(int a,int b){if(a%b==0){return b;}else return gcd(b,a%b);}
int lcm(int a,int b){if(a==0){return b;} return a/gcd(a,b)*b;}

struct UnionFind{
	
	std::vector<int> data;
	
	UnionFind(int size): data(size, -1) {}
	
	bool unite(int x, int y){
		x=root(x);
		y=root(y);
		if( x != y ){
			if( data[y] < data[x] ) std::swap(x, y);
			data[x] += data[y];
			data[y] = x;
		}
		return x!=y;
	}

	bool find(int x, int y){
		return root(x) == root(y);
	}
	
	int root(int x){
		return (data[x] < 0)? x : data[x]=root(data[x]);
	}
	
	int size(int x){
		return -data[root(x)];
	}
};

map<P,int> mp;

signed main(){
	int n,k,l;
	cin>>n>>k>>l;
	
	UnionFind uf_1=UnionFind(n+1);
	UnionFind uf_2=UnionFind(n+1);
	
	for(int i=0; i<k; i++){
		int a,b; cin>>a>>b;
		uf_1.unite(a, b);
	}
	for(int i=0; i<l; i++){
		int a,b; cin>>a>>b;
		uf_2.unite(a, b);
	}
	for(int i=1; i<=n; i++){
		mp[mk(uf_1.root(i), uf_2.root(i))]++;
	}
	for(int i=1; i<=n; i++){
		cout<<mp[mk(uf_1.root(i), uf_2.root(i))]<<" ";
	}
	
	cout<<en;
}


