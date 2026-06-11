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

long long n,a[100005],x,y,dp[100005],r,v[100005],pos=1;

vector <int> g[100005];

void DFS(int nod, int p){
    if(g[nod].size()==1){
        dp[nod]=a[nod];
        return;
    }
    dp[nod]=2*a[nod];
    for(int i : g[nod]){
        if(i==p) continue;
        DFS(i,nod);
        dp[nod]-=dp[i];
        if(dp[i]>a[nod]) pos=0;
    }
    if(dp[nod]>a[nod]) pos=0;
}

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<n;i++) cin >> x >> y,g[x].pb(y),g[y].pb(x);
    r=1;
    if(n==2){
        if(a[2]!=a[1]) cout << "NO";
        else cout << "YES";
        return 0;
    }
    while(g[r].size()==1) r++;
    DFS(r,-1);
    for(int i=1;i<=n;i++){
        if(dp[i]<0){
            cout << "NO";
            return 0;
        }
    }
    if(dp[r] || !pos)
        cout << "NO";
    else
        cout << "YES";

}
