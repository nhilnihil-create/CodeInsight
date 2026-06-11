#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
long N,M;
vector<int> g[size];
int visit[size] = {}; long n;
bool dfs(int v){
    bool flag = true;
    for(int u:g[v]){
        if(visit[u] == -1){
            n++;
            visit[u] = visit[v] ^ 1;
            if(!dfs(u)) flag = false;
        }else{
            if(visit[v] == visit[u]) flag = false;
        }
    }return flag;
}
int main(){
	cin>>N>>M;
	int a,b;
	rep(i,0,M){
		cin>>a>>b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	long ans = N * N;
    long cnt = 0; long sum = 0; long bip = 0;
    rep(i,0,N) visit[i] = -1;
	rep(i,0,N)if(visit[i] == -1 && g[i].size()){
		n = 1;
        visit[i] = 1;
		if(dfs(i)) bip++;
        cnt++;
        sum += n;
	}cout<<ans - sum * sum + cnt * cnt + bip * bip<<endl;
}