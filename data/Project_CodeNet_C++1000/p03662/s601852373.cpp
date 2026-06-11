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
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int N;
vector<vector<int>> G;

void dfs(int u,int p,vector<int> &dist){
    for(int v : G[u]){
        if(v == p) continue;
        dist[v] = dist[u]+1;
        dfs(v,u,dist);
    }
}

int main(){
    cin >> N;
    G.resize(N);
    rep(i,N-1){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist1(N);
    vector<int> dist2(N);
    dfs(0,-1,dist1);
    dfs(N-1,-1,dist2);

    int cnt = 0;

    repr(i,1,N-1){
        if(dist1[i] <= dist2[i]){
            cnt++;
        }
    }
    int cnt2 = N-2-cnt;
    if(cnt > cnt2){
        cout << "Fennec" << endl;
    }
    else if(cnt < cnt2){
        cout << "Snuke" << endl;
    }
    else{
        if(N % 2 == 0){
            cout << "Snuke" << endl;
        }
        else{
            cout << "Fennec" << endl;
        }
    }
}
