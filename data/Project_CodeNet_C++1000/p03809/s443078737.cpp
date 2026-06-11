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
double Pi = 3.1415926535897932384626;
long long int mod = 1000000007;

vector<ll> G[500005];
vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "RULD";
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
    //abcのbed乗を計算する
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
ll n,m,num;
ll a,b,c,d,e,f,g,h,r;
ll vnum[500005],x[500005];
bool dame;
bool check[500005];

ll dfs(ll v){
	//vの子について
	check[v] = true;
	ll in,out;
	ll a = 0;
	ll b = 0;
	ll d = 0;
	for(int i=0;i<G[v].size();i++){
		ll av = G[v][i];
		if(check[av])continue;
		//if(v==2)deba(av);
		d++;
		c = dfs(av);
		a += c;
		b = max(b,c);		
	}
	if(G[v].size() == 1){
		out = x[v];
	}else{
		in = a - x[v];
		out = x[v] - in;
		if(in < 0)dame = true;
		if(a - b < in)dame = true;
	}
	//out = x[v] - in;
	//deba(v);
	//deba(out);
	//deba(a);
	//p("----");
	if(out < 0)dame = true;
	check[v] = false;
	return out;
}


int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x[i];
	}
	for(i=0;i<n-1;i++){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	a = 0;
	r = 0;
	for(i=1;i<=n;i++){
		if(G[i].size() > a){
			a = G[i].size();
			r = i;
		}
	}
	if(dfs(r) != 0){
		dame = true;
	}
	if(n==2 && x[1] == x[2])dame = false;
	// r = 根

	
	
	if(dame){
		p("NO");
	}else{
		p("YES");
	}
    //dfs(1,0));
    //p(ans);
    return 0;
}