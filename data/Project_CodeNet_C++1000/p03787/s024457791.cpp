#include <bits/stdc++.h>
#define pb push_back
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int N=110000;
int v[N], s, nbp;
vi adj[N];

void dfs(int x, int t) {
    v[x]=t;
    s++;
    for(int y:adj[x]) {
        if(v[y]==t) nbp=1;
        if(!v[y]) dfs(y, -t);
    }
}

int main() {
    int i, n, m, x, y;
    ll c, c1, cbp;
    scanf("%d%d", &n, &m);
    while(m--) {
        scanf("%d%d", &x, &y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    c=c1=cbp=0;
    for(i=1; i<=n; i++) if(!v[i]) {
        s=nbp=0;
        dfs(i, 1);
        if(s==1) c1++;
        else {
            c++;
            if(!nbp) cbp++;
        }
    }
    printf("%lld\n", 2*c1*n-c1*c1+c*c+cbp*cbp);
    return 0;
}