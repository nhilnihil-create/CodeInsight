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
ll a,b,c,e,f,g,h;
ll x[800005],y[800005],z[900005];
ll in[800005];
ll vnum = 0,sum,ans;
bool dame;
bool check[500005];

ll dfs(ll a,ll space){
	ll num = G[a].size();
	vnum += num;
	
    if(num == 0){
        return 0;
    }else{
		for(int i=0;i<num;i++){
			x[i + space] = dfs(G[a][i],vnum);
		}
		sort(x + space,x+num + space);
		ll a = 0;
		for(i = 0;i<num;i++){
			a = max(a,x[i+space] + num - i);
		}
		return a;

    }
}

int main(){
    cin>>n;
    for(i=0;i<n-1;i++){
        cin >> a;
        //i+2番目はaに負けた
        G[a].pb(i+2);        
    }
    p(dfs(1,0));
    //p(ans);
    return 0;
}