#define rep(i,a,b) for(int i=a;i<b;++i)
#define repr(i,a,b) for(int i=a,i > b;--i)
#define mm(lamb, tttt) memset(lamb, tttt, sizeof lamb)

#define null NULL
#define eps 0.000000001
#define mod 1000000007

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define ALL(V) V.begin(), V.end()
#define sz(V) (ll)V.size()
#define _ <<" "<<

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <iterator>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <limits.h>
#include <iomanip>
#include <cctype>
#include <numeric>
#include <complex>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <double, double> ii;
typedef pair<int, pair<int,int> > iii;
typedef vector<pair<int,int> > vii;

using cd = complex<double> ;
const double PI = acos(-1);

const int N=2e5+5;
int n,k,l;
vi adj1[N];
vi adj2[N];
int comp1cntr;
int comp2cntr;
vii comp(N);
vi comp1(N);
vi vis1(N);
vi comp2(N);
vi vis2(N);
// pl then for each vertex i have (a,b) values then i can store them and sor then i guess upper and lower bound will do the trick so this was mainly a DS problem
// hmm is till dont quite get the feeling.but now you think about it each query in logn time you need binary serach and hence sorting after it seems obvious.

void dfs1(int s){
	comp[s].first=comp1cntr;
	comp1[s]=comp1cntr;
	vis1[s]=true;
	for(auto v : adj1[s]){
		if(!vis1[v]) dfs1(v);
	}
}

void dfs2(int s){
	comp[s].se=comp2cntr;
	comp2[s]=comp2cntr;
	vis2[s]=true;
	for(auto v : adj2[s]){
		if(!vis2[v]) dfs2(v);
	}
}

int main(){
	cin>>n>>k>>l;

	for(int i=0;i<k;i++){
		int a,b;
		cin>>a>>b;
		adj1[a].pb(b);
		adj1[b].pb(a);
	}
	for(int i=0;i<l;i++){
		int a,b;
		cin>>a>>b;
		adj2[a].pb(b);
		adj2[b].pb(a);
	}
	for(int i=1;i<=n;i++){
		if(vis1[i]) continue;
		comp1cntr++;
		dfs1(i);
	}
	for(int i=1;i<=n;i++){
		if(vis2[i]) continue;
		comp2cntr++;
	 	dfs2(i);
	}
	//for(int i=1;i<=4;i++) cout<<comp1[i]<<" "<<comp2[i]<<" "<<comp[i].fi<<" "<<comp[i].se<<endl;

	sort(comp.begin(),comp.end());
	for(int i=1;i<=n;i++){
		cout<<upper_bound(comp.begin(),comp.end(),mp(comp1[i],comp2[i]))-lower_bound(comp.begin(),comp.end(),mp(comp1[i],comp2[i]))<<" ";
	}
	cout<<endl;
}



