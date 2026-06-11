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

int N;
ll A[SIZE];
vi hen[SIZE];
bool ans=true;
ll dfs(int a,int fr){
	ll score=A[a];
	if(hen[a].size()>1)score*=(ll)2;//2*score-sum 
	for(int i=0;i<hen[a].size();i++){
		if(hen[a][i]==fr)continue;//skip
		ll hoge=dfs(hen[a][i],a);
		if(hoge>A[a])ans=false;
		score-=hoge;
	}
	if(score>A[a])ans=false;
	if(score<0)ans=false;
	if(fr==-1&&score!=0)ans=false;
	return score;
}
int main()
{

 
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;a--;b--;
		hen[a].pb(b);
		hen[b].pb(a);
	}
	if(N==2){
		if(A[0]==A[1])cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		return 0;
	}
	int from=-1;
	for(int i=0;i<N;i++){
		if(hen[i].size()>1){
			from=i;
			break;
		}
	}
	dfs(from,-1);
	if(ans)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}