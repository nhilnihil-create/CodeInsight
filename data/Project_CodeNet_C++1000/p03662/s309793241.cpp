#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#include<list>
#include<limits>
#include<bitset>
#include<ctype.h>
#include<set>
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
const ll MOD=1000000007LL;
const ll INF=1000000000;
const int MAX=100001;
int da[MAX];
int db[MAX];
vector<int> G[MAX];
void dfsa(int v,int d){
    da[v]=d;
    for(int i=0;i<(int)G[v].size();i++){
        if(da[G[v][i]]==INF){
            dfsa(G[v][i],d+1);
        }
    }
}
void dfsb(int v,int d){
    db[v]=d;
    for(int i=0;i<(int)G[v].size();i++){
        if(db[G[v][i]]==INF){
            dfsb(G[v][i],d+1);
        }
    }
}
int main() {   
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        da[i]=INF;
        db[i]=INF;
    }
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfsa(1,0);
    dfsb(n,0);
    int br=0;int wh=0;
    for(int i=1;i<=n;i++){
        if(da[i]<=db[i]){
            br++;
        }else{
            wh++;
        }
    }
    if(br>wh){
        cout<<"Fennec"<<endl;
    }else{
        cout<<"Snuke"<<endl;
    }
    getchar();
    getchar();
}