#include <iostream>
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
const int mod = 1000000007;
// memset(a,0,sizeof(a)); →全部０にする
 
vector<int> G[100005];
std::vector<P> tree[100010];
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
 
#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define re(i,a,b) for(i=a;i<=b;i++)
 
ll i,j,k,ii,jj;
ll n,m,sum,num=INF;
ll ans;
ll a,b,c,d,e;
ll x[100005],y[100005],z[100005];
ll xa[100005],ya[100005],za[100005];
ll dp[100005];
string s;

int main(){
	cin>>n>>m;
    for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>s;
			if(s=="snuke"){
				char sa[10];
				sa[10]=j+'A';
				cout<<sa[10]<<i+1<<endl;
				return 0;
			}
		}
	}

}