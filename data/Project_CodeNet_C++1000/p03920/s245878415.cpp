#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <vector>
 
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
#define e cout<<endl;
#define pe(x) cout<<x<<" ";
#define re(i,a,b) for(i=a;i<=b;i++)
 
ll i,j,k,l,ii,jj;
int n,m;
ll x,y;
int a;
ll ans=0;
ll sum=0;

int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		sum+=i;
		if(sum>n)break;
	}
	a=i;
	if(n==1){
		p(1);
	}else{
		for(i=1;i<=a;i++){
			if(i!=sum-n)p(i);
		}
	}
	return 0;
}