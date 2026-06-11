#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <utility>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
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
 
ll i,j,k,l,ii,jj;
ll n,t;
ll a[100005];
ll syo=INF,dai=0;
ll memo=0;
ll ans;

int main(){
	cin>>n>>t;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		if(syo>a[i]){
			syo=a[i];
		}else if(a[i]-syo>dai){
			ans=1;
			dai=a[i]-syo;
		}else if(a[i]-syo==dai){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;


}