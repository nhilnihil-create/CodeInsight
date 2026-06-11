#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
//#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
typedef long long ll;
#define int ll
#define uset unordered_set
#define umap unordered_map
typedef pair<int,int> P;
struct edge{int to,cost;};
#define REP(i,n) for(int i=0;i<(n);i++)
const int INF=100000000000000000;
const int MOD=1000000007;

int N,W;
int w[110],v[110];
map<int,int> dp[103];
set<P> U,U2;

int DP(int a,int b){
	if(U.find(make_pair(a,b))!=U.end()){
		return dp[a][b];
	}
	if(a==N){
		if(b<=W){
			return 0;
		}
		else{
			return -INF;
		}
	}
	U.insert(make_pair(a,b));
	return dp[a][b]=max(DP(a+1,b+w[a])+v[a],DP(a+1,b));
}

signed main(){
	cin>>N>>W;
	REP(i,N){
		cin>>w[i]>>v[i];
	}
	int ans=DP(0,0);
	cout<<ans<<endl;
	return 0;
}
