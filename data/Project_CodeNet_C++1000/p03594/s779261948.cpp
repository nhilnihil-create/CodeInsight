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
char f[2001][2001];
char c[]={'R', 'Y', 'B', 'G'};
int n, m, d;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(m);
    read(d);
    int x=0;
    for(int i=0; i<1200; i+=d){
        int c=(x%2)?2:0;
        for(int j=0; j<1200; j+=d){
            FFOR(k, 0, d) FFOR(l, 0, d) f[i+k][j+l]=c;
            c=(c+1)%4;
        }
        x++;
    }
    FFOR(i, 0, n){
        FFOR(j, 0, m){
            putchar(c[f[i+j][j+499-i]]);
        }
        putchar('\n');
    }
}