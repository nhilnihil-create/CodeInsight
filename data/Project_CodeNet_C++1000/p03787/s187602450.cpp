#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <iomanip>
#include <complex>
#include <bitset>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f3f3f3f3fLL
#define SIZE 100005

using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef pair<int,ll> pill; typedef pair<ll,int> plli; 
typedef pair<double, int> pdi;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
typedef complex<double> P;
long long int MOD = 1000000007;
int N,M;
vi g[SIZE];
bool used[SIZE];
int guki[SIZE]={0};
ll cntX=0,cntY=0;
bool flag;
void dfs(int a){
	used[a]=true;
	for(int i=0;i<g[a].size();i++){
		int next=g[a][i];
		if(guki[next]==guki[a])flag=false;
		if(!used[next]){
			guki[next]=guki[a]*-1;
			dfs(next);
		}
		
	}
}
int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;u--;v--;
		g[u].pb(v);g[v].pb(u);
	}
	ll ans=0;
	int cnt=0;
	rep(i,N)used[i]=false;
	for(int i=0;i<N;i++){
		if(g[i].size()==0)cnt++,used[i]=true;
	}
	ans+=(ll)N*(ll)N-(ll)(N-cnt)*(ll)(N-cnt);
	for(int i=0;i<N;i++){
		if(!used[i]){
			guki[i]=1;
			flag=true;
			dfs(i);
			if(flag){
				cntY++;
			}else{
				cntX++;
			}
		}
	}
	ans+=(cntX+cntY)*(cntX+cntY)+cntY*cntY;
	cout<<ans<<endl;
}