#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstring>
#include <fstream>
#define FI first
#define SE second
#define VE vector<int>
#define PB push_back
#define PA pair<int,int>
#define MA make_pair
#define LLI long long int
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define POS(i) cout<<(i?"POSSIBLE":"IMPOSSIBLE")<<endl
#define Pos(i) cout<<(i?"Possible":"Impossible")<<endl
#define co(i) cout<<i<<endl
using namespace std;
//
const int INF=1e9+7;
const int MOD=1e9+7;
//
const int vmax=100001;
vector<PA> g[vmax];
int dist1[vmax]={},dist2[vmax]={};

void dfs(int s,int t,int k){
    dist1[s]=k;
    for(auto &i:g[s]){
	    if(i.FI==t) continue;
	    dfs(i.FI,s,k+i.SE);
    }
}
void dfs2(int s,int t,int k){
    dist2[s]=k;
    for(auto &i:g[s]){
	    if(i.FI==t) continue;
	    dfs2(i.FI,s,k+i.SE);
    }
}

int main(){
    int n; cin>>n;
    FOR(i,0,n-1){
        int a,b; cin>>a>>b;
        a--; b--;
        g[a].PB(PA(b,1));
        g[b].PB(PA(a,1));
    }
    dfs(0,-1,0);
    dfs2(n-1,-1,0);
    int fene=0,snuke=0;
    FOR(i,0,n){
        if(dist1[i]<=dist2[i]) fene++;
        else snuke++;
    }
    cout<<(fene>snuke?"Fennec":"Snuke")<<endl;
}
