#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <utility>
#include <cmath>
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
 
struct edge{int to,cost;};
vector<int> G[100005];
 
long long int n,m,i,j=1,t;
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1,};
 
std::vector<P> tree[100010];
long long int dp[100005];
bool flag=false,toke;
bool used[100005];
char s[20];

ll ans=0;
long long int x,y,a,b;




int main(){
	cin>>x>>y;
	if(abs(x-y)<=1){
		cout<<"Brown";
	}else{
		cout<<"Alice";
	}
	cout<<endl;
	return 0;
}