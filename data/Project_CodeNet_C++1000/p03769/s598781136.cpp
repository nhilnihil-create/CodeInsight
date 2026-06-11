#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;//*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
vector<int> v;
void solve(ll n){
	if(n==1){
//		cout << v.size() << endl;
		return;
	}
	else if(n&1){
		solve(n-1);
		v.insert(v.begin(),v.size()+1);
//		debug(v[0]),debug(v.size());
	}else {
		solve(n/2);
		v.pb(v.size()+1);
	}
	
}
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
	ll n;
	cin>>n;
	solve(n+1);
	int tmp=v.size();
	printf("%d\n",tmp*2);
	for(auto u:v)printf("%d ",u);
	rep(i,1,tmp)printf("%d%c",i," \n"[i==tmp]);
}