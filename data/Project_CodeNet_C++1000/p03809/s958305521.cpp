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
int A[110000];
vector<int>g[110000];
bool dame=false;
long long dfs(int a,int b){
	long long rem=A[a];
	if(g[a].size()>1)rem*=2;
	for(int i=0;i<g[a].size();i++){
		if(b==g[a][i])continue;
		long long v=dfs(g[a][i],a);
		if(v>A[a])dame=true;
		rem-=v;
	}
	if(rem>A[a])dame=true;
	if(rem<0)dame=true;
	if(b==-1&&rem)dame=true;
	return rem;
}
int main(){
	int N;cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N-1;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	if(N==2){
		if(A[0]==A[1])cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		return 0;
	}
	int at=-1;
	for(int i=0;i<N;i++){
		if(g[i].size()>1){
			at=i;break;
		}
	}
	if(at==-1)return 1;
	dfs(at,-1);
	if(dame)printf("NO\n");else printf("YES\n");
}
