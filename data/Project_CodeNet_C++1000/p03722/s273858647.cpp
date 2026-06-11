#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
//#define MOD 1000000007
#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int N,M;

bool visitable[1010];
tuple<int,int,int> G[2010];
vector<int> G2[1010],rG[1010];
bool used1[1010],used2[1010];

void dfs(int u){
    if(used1[u]) return;
    used1[u] = true;
    for(int v : G2[u]) dfs(v);
}

void rdfs(int u){
    if(used2[u] || !used1[u]) return;
    used2[u] = true;
    visitable[u] = true;
    for(int v : rG[u]) rdfs(v);
}


int main(){
    cin >> N >> M;
    rep(i,1010){
        visitable[i] = false;
        used1[i] = false;
        used2[i] = false;
    }
    rep(i,M){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        c = -c;
        G[i] = tie(a,b,c);
        G2[a].push_back(b);
        rG[b].push_back(a);
    }
    dfs(0);
    rdfs(N-1);

    vector<ll> dist(N,LINF);
    dist[0] = 0;
    int cnt = 0;
    while(true){
        cnt++;
        bool update = false;
        rep(i,M){
            int a,b,c;
            tie(a,b,c) = G[i];
            if(!visitable[a]||!visitable[b]) continue;
            if(dist[b] > dist[a]+c){
                update = true;
                dist[b] = dist[a]+c;
            }
        }
        if(!update) break;
        if(cnt == N){
            cout << "inf" << endl;
            return 0;
        }
    }
    cout << -dist[N-1] << endl;
}

    

