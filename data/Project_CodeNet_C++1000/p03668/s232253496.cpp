#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define lg length()
#define pb push_back
ifstream in("file.in");
ofstream out("file.out");
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005

int n,a[100005],x,y,ans,v[100005];

vector <int> g[100005];

void DFS(int nod){
    a[nod]=1; v[nod]=1;
    int add=0;
    for(int i : g[nod]){
        if(v[i]) continue;
        DFS(i);
        add^=a[i];
    }
    a[nod]+=add;
}

int32_t main(){
    ios_base :: sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    DFS(1);
    for(int i : g[1]) ans^=a[i];
    if(ans) cout << "Alice";
    else cout << "Bob";
}
