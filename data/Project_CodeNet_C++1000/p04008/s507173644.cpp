#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MX=100010, inf=2e9;

int n, k;
vector<int> G[MX];
int A[MX];
int ans=0;

int dep[MX];
int D[MX];

void dfs1(int v, int now=0){
    dep[v]=now;
    for(int x:G[v]) dfs1(x,now+1);
}

int up(int x){
    int m=min(n,k-1);
    for(int i=1; i<=m; i++)
        if(x==1) break;
        else x=A[x];
    return x;
}

vector<pii> V;
bool done[MX];

void erase(int v){
    done[v]=true;
    for(int x:G[v])
        if(!done[x])
            erase(x);
}

void solve(){
    dfs1(1);
    for(int i=1; i<=n; i++){
        V.push_back({dep[i], i});
    }
    sort(V.begin(), V.end(), greater<pii>());
    for(pii &q:V){
        int v=q.second;
        if(done[v]) continue;
        done[v]=true;
        int p=up(v);
        erase(p);
        if(A[p]!=1) ans++;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>A[i];
    if(A[1]!=1) A[1]=1, ans++;
    for(int i=2; i<=n; i++)
        G[A[i]].push_back(i);

    solve();

    cout<<ans;
    return 0;
}