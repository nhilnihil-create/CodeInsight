#include <iostream>
#include <cassert>
#include <climits>
#include <bitset>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>
 
using namespace std;
typedef long long ll;
 
 
typedef pair<ll,ll> P;
long long int INF = 1e18;
double Pi = 3.141592653589;
long long int mod = 1000000007;
// memset(a,0,sizeof(a)); →全部０にする
 
vector<ll> G[100005];
vector<P> tree[100010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
//↓,→,↑,←
 
#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<x;
#define re(i,a,b) for(i=a;i<=b;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define deba(x) cout<< #x << " = " << x <<endl

ll rui(ll abc,ll bed){
	//aのb乗を計算する
	if(bed==0){return 1;}
	else{
		ll ced = rui(abc,bed/2);
		ced *= ced;
		ced %= mod;
		if(bed%2==1){ced*=abc; ced%=mod;}
		return ced;
	}
} 

ll i,j,k,ii,jj;
ll n,m,num,sum;
ll ans;
ll a,b,c,d,e,f,g,h,w,v;
char s[500][500];
ll x[800005],y[800005],z[900005];
ll timee[500005];
ll color[500005];
ll kyori[500005];

void paint(ll v,ll d,ll c,ll t){
	//p("結果");
	//pe(v);pe(d);p(c);
	if(color[v]==0){
		//pe(c);p(v);
		color[v] = c;
		num++;
	}
	if(num==n || kyori[v] > d)return;
	timee[v] = t;
	kyori[v] = d;
	if(d==0)return ;
	for(int i=0;i<G[v].size();i++){
		if(timee[G[v][i]] == t && kyori[G[v][i]] >= d)continue;
		paint(G[v][i],d-1,c,t);
	}
}

int main(){	
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	cin>>k;
	for(i=0;i<k;i++){
		cin>>x[i]>>y[i]>>z[i];
	}
	reverse(x,x+k);
	reverse(y,y+k);
	reverse(z,z+k);
	for(a=0;a<k;a++){
		paint(x[a],y[a],z[a],a+5);
	}
	for(i=1;i<=n;i++){
		p(color[i]);
	}	
	return 0;
}