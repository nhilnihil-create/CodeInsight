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
#define taskname "F"
const ll base=1000000007;
int n;
ll it[4000001];
ll lz[4000001];
void update(int i, int l, int r, int u, int v, ll x){
    if(l>v||r<u) return;
    if(u<=l&&v>=r){
        it[i]=(it[i]+x)%base;
        lz[i]=(lz[i]+x)%base;
    }
    else{
        int m=(l+r)/2;
        it[2*i]=(it[2*i]+lz[i])%base;
        lz[2*i]=(lz[2*i]+lz[i])%base;
        it[2*i+1]=(it[2*i+1]+lz[i])%base;
        lz[2*i+1]=(lz[2*i+1]+lz[i])%base;
        lz[i]=0;
        update(2*i, l, m, u, v, x);
        update(2*i+1, m+1, r, u, v, x);
        it[i]=(it[2*i]+it[2*i+1])%base;
    }
}
ll get(int i, int l, int r, int u, int v){
    if(l>v||r<u) return 0;
    if(u<=l&&v>=r) return it[i];
    else{
        int m=(l+r)/2;
        it[2*i]=(it[2*i]+lz[i])%base;
        lz[2*i]=(lz[2*i]+lz[i])%base;
        it[2*i+1]=(it[2*i+1]+lz[i])%base;
        lz[2*i+1]=(lz[2*i+1]+lz[i])%base;
        lz[i]=0;
        return get(2*i, l, m, u, v)+get(2*i+1, m+1, r, u, v);
    }
}
ll ans=0;
ll f[1000001];
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    f[0]=1;
    FFOR(i, 0, n){
        if(i) f[i]=get(1, 1, n, i, i);
        if(i+3<=n) update(1, 1, n, i+3, n, f[i]);
        update(1, 1, n, i+1, i+1, f[i]);
    }
    ll sq=n-1;
    sq=(sq*sq)%base;
    ll ans=(f[n-1]*n)%base;
    DFOR(i, n-2, 0){
        ans=(ans+f[i]*sq)%base;
        ans=(ans+f[i]*(max(n-max(n-i-1, 2)+1, 0)))%base;
    }
    ans=(ans+base)%base;
    writeln(ans);
}