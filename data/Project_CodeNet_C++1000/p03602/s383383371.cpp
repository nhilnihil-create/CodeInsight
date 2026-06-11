#include<ctime>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath> 
#include<cstring> 
#include<cassert>
#include<string>
#include<sstream>
#include<fstream>
#include<deque>
#include<queue>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<set>
#include<bitset>
#include<iomanip>
#include<utility>
#include<functional>
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
#include<cwchar>
#include<cwctype>
#include<exception>
#include<locale>
#include<numeric>
#include<new>
#include<stdexcept>
#include<limits>
using namespace std;

#define ll long long
#define INF 1e9
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
#define pii pair<int,int>
#define sz(s) s.size()
#define all(s) (s.begin(),s.end())
inline void Fail(){
	printf("-1");
	exit(0);
}

const int maxn=305;
int n;
ll dist[maxn][maxn];
bool done[maxn][maxn];
ll ans;

int main(){
	scanf("%d",&n);
	rep(i,n)rep(j,n){
		scanf("%lld",&dist[i][j]);
		ans+=dist[i][j]; 
	}
	rep(k,n)rep(i,n)rep(j,n){
		if(dist[i][k]+dist[k][j]<dist[i][j])Fail();
		if(i!=k&&j!=k&&dist[i][k]+dist[k][j]==dist[i][j]&&!done[i][j])
		ans-=dist[i][j],done[i][j]=true;
	}
	printf("%lld",ans/2);
	return 0;
}