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
ll dp[500][500];

int main(){	
	cin>>h>>w>>n;
	for(i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	map<P,ll> cnt; 
	for(i=0;i<n;i++){
		for(j=-1;j<=1;j++){
			for(k=-1;k<=1;k++){
				if(x[i]+j <2 || y[i]+k<2 || x[i]+j>=h || y[i]+k>=w)continue;
				cnt[P(x[i]+j,y[i]+k)]++;
			}
		}
	}
	z[0] = (h-2) * (w-2);
	for(map<P,ll>::iterator a=cnt.begin();a!=cnt.end();a++){
		z[0]--;
		z[a->second]++;
	}
	for(i=0;i<10;i++){
		p(z[i]);
	}	
	return 0;
}