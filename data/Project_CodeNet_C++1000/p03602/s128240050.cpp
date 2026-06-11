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
const ll inf=(1e9)+1;
priority_queue <pair <ll, pair <int, int> > > q;
int n;
ll a[301][301];
ll c[301][301];
int u, v;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    FOR(i, 1, n) FOR(j, 1, n) read(a[i][j]);
    FOR(i, 1, n) FOR(j, i+1, n) q.push(mp(-a[i][j], mp(i, j)));
    FOR(i, 1, n) FOR(j, 1, n) c[i][j]=inf;
    FOR(i, 1, n) c[i][i]=0;
    ll ans=0;
    while(!q.empty()){
        u=q.top().second.first;
        v=q.top().second.second;
        q.pop();
        if(c[u][v]<a[u][v]){
            puts("-1");
            return 0;
        }
        if(c[u][v]>a[u][v]){
            FOR(i, 1, n) FOR(j, 1, n){
                c[i][j]=min(c[i][j], c[i][u]+a[u][v]+c[v][j]);
                c[i][j]=min(c[i][j], c[i][v]+a[u][v]+c[u][j]);
            }
            ans+=a[u][v];
        }
    }
    write(ans);
}