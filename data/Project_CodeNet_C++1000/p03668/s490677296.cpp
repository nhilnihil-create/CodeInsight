#pragma GCC optimize "-O3"
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NumberOfOnes __builtin_popcount
#define LSOne(S) (S & (-S))
#define ll long long
#define two pair<int,int>
#define twoll pair<ll,ll>
#define four pair<two,two>
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define y1 y1922
#define INF 1000000000000000000
#define P 1000000007
#define lmax 1000000000
#define nn 1000003
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>
#define vtwo vector<two>
#define ALL(container) (container).begin(), (container).end()
#define sz(container) (int)(container.size())
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define mid(a,b) (a+b>>1)
#define minN 0
#define maxN 10000000
#define na(x) ((x)<P?(x):(x)-P)
#define ab(a) (-(a)<(a)?(a):-(a))
#define FAST std::ios::sync_with_stdio(false)
#define xRand mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define rnd rng
#define IT iterator
typedef
tree<
  int,// aq pair<int,int> shegidzlia
  null_type,
  less/*_equal*/<int>,// aqac
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;
// '_equal' mashin ginda roca multiset gchirdeba
template<class key, class value,class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
ordered_map<int, int> my_map;
inline int rin(){
	int x=0,w=1;char ch=getchar();
	while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if (ch=='-') w=0,ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return w?x:-x;
}
inline int bin(){
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
int n,ans,a,b,w[100004];
vector<int>v[100004];
void go(int sad,int saidan){
	w[sad]=0;
	for(auto i:v[sad]){
		if(i==saidan) continue;
		go(i,sad);
		w[sad]^=w[i]+1;
	}
}
int main(){FAST;xRand;
cin>>n;
for(int i=1;i<n;i++){
	cin>>a>>b;
	v[a].pb(b);
	v[b].pb(a);
	
}
go(1,-1);
if(w[1]==0){
	cout<<"Bob"<<endl;
}else{
	cout<<"Alice"<<endl;
}
}
/*

                   *         *
                  * *       * *
                 *   *     *   *
                *     *   *     *
                 *   *   * *   *
                  *   *   *   *
                   *   * *   *
                     *  *   *
					   *  *


*/

