#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "D"
int n, k, l;
vector <int> g[200001][2];
bool done[200001][2];
int cc[200001][2];
vector <int> c[400001];
int f[400001];
int ans[200001];
int cnt=0;
void dfs(int u, int i){
    done[u][i]=1;
    cc[u][i]=cnt;
    c[cnt].pb(u);
    for(int v: g[u][i]) if(!done[v][i]) dfs(v, i);
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(k);
    read(l);
    int u, v;
    FOR(i, 1, k){
        read(u);
        read(v);
        g[u][0].pb(v);
        g[v][0].pb(u);
    }
    FOR(i, 1, l){
        read(u);
        read(v);
        g[u][1].pb(v);
        g[v][1].pb(u);
    }
    FOR(i, 1, n) if(!done[i][0]){
        cnt++;
        dfs(i, 0);
    }
    int m=cnt;
    FOR(i, 1, n) if(!done[i][1]){
        cnt++;
        dfs(i, 1);
    }
    FOR(i, 1, m){
        for(int x: c[i]) f[cc[x][1]]++;
        for(int x: c[i]) ans[x]=f[cc[x][1]];
        for(int x: c[i]) f[cc[x][1]]--;
    }
    FOR(i, 1, n){
        write(ans[i]);
        putchar(' ');
    }
}