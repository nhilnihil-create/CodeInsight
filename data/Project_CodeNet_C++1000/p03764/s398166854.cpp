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
priority_queue <ll,vector<ll>,greater<ll>> pqls;
priority_queue <P,vector<P>,greater<P>> pqps;
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
ll a,b,c,d,e,f,g,h,w;
char s[500][500];
ll x[800005],y[800005],z[900005];
ll xd[600006],yd[600006];
ll xm[500005],ym[500005];
ll dp[500][500];

int main(){	
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>x[i];
	}
	for(i=0;i<m;i++){
		cin>>y[i];
	}
	for(i=0;i<n-1;i++){
		xd[i] = x[i+1] - x[i];
		xd[i] %= mod;
	}
	for(i=0;i<m-1;i++){
		yd[i] = y[i+1] - y[i];
		yd[i] %= mod;
	}
	for(i=0;i<n-1;i++){
		xm[i] = (((xd[i] * (i+1))%mod) * (n-i-1))%mod;
	}
	for(i=0;i<m-1;i++){
		ym[i] = yd[i] * (i+1);
		ym[i] %= mod;
		ym[i] *= (m-i-1);
		ym[i] %= mod;
	}
	ll sumx=0,sumy=0;
	for(i=0;i<n-1;i++){
		sumx += xm[i];
		sumx %= mod;
	}
	for(i=0;i<m-1;i++){
		sumy += ym[i];
		sumy %= mod;
	}
	p(sumx * sumy %mod);
	return 0;
}