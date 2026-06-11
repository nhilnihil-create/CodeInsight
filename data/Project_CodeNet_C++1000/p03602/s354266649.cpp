#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <cassert>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define PER(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)((x).size()))
#define ALL(t) t.begin(),t.end()
#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;
#define DBG(vari) cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
template<class T> ostream &operator<<(ostream &os, vector<T> V){ os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]"; } 
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) { return os<<"("<<P.fi<<","<<P.se<<")"; }
#define flash ios_base::sync_with_stdio(0);
#define read freopen("1.in","r",stdin);
#define write freopen("1.out","w",stdout);
inline bool EQ(ld a,ld b) {return fabs(a-b)<=(1e-7);}
const ll mod=(1e9+7);
const ld pi=(acos(-1));
//CUT BEGINS

int main() {
	flash; bool flag=0;
	int n; cin>>n;
	ll ans=0,w[n+5][n+5],imp[n+5][n+5]; clr(w),clr(imp);
	REP(i,1,n) REP(j,1,n) cin>>w[i][j];
	REP(k,1,n) REP(i,1,n) REP(j,1,n) if(w[i][j]>w[i][k]+w[k][j]) flag=1;
	if(flag) {
		cout<<-1; return 0;
	}
	REP(k,1,n) REP(i,1,n) REP(j,1,n) if(k!=i&&k!=j&&w[i][j]==w[i][k]+w[k][j]) imp[i][j]=1;
	REP(i,1,n) REP(j,1,n) if(!imp[i][j]) ans+=w[i][j];
	cout<<ans/2;
	return 0;
}