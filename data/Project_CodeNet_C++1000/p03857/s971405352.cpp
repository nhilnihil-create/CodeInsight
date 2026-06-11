#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define REPr(i,n) for(int i=(n)-1;i>=0; --i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
#define rFORq(i, m , n) for(int i = (n);i >=(m);--i)
#define SCD(n) scanf("%d",&n)
#define SCD2(m,n) scanf("%d%d",&m,&n)
#define SCD3(m,n,k) scanf("%d%d%d",&m,&n,&k)
#define SCLLD(n) scanf("%lld",&n)
#define SCLLD2(m,n) scanf("%lld%lld",&m,&n)
#define SCLLD3(m,n,k) scanf("%lld%lld%lld",&m,&n,&k)
#define PB push_back
#define MP make_pair
#define ARSCD(A,N) REP(i,N){SCD(A[i]);}
#define ARSCD1(A,N) FORq(i,1,N){SCD(A[i]);}
#define VSCD(v,N) REP(i,N){int x; SCD(x); v.PB(x);}
#define VSCLLD(v,N) REP(i,N){long long x; SCLLD(x); v.PB(x);}
#define PRINTD(n) printf("%d\n",n)
#define PRINTLLD(n) printf("%lld\n",n)
#define DEBUG printf("%s\n","debug")
#define fst first
#define snd second
#define SIN(x,S) (S.count(x) != 0)
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector < VI > VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
////////////////////////////////////////////////////////////////////
struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size,-1) { }

    int root(int x){
        if (data[x] < 0) return x;
        else return data[x] = root(data[x]);
    }

    int size(int x){
        return -data[root(x)];
    }

    bool isConnect(int x,int y){
        return root(x) == root(y);
    }

    bool connect(int x , int y){
        x = root(x);
	    y = root(y);
	
        if(x==y) return false;
        
        if(data[x] > data[y]){
            x ^= y;
            y ^= x;
            x ^= y;
        }
        
        data[x] = data[x] + data[y]; // membersize++
        data[y] = x;
        return true;
    }
};

UnionFind U1(200002);
UnionFind U2(200002);

int main(){ 
    int N,K,L; SCD3(N,K,L);
    REP(i,K){
        int p,q; SCD2(p,q);
        U1.connect(p,q);
    }
    REP(j,L){
        int r,s; SCD2(r,s);
        U2.connect(r,s);
    }

    map< PII ,int> f;

    FORq(i,1,N){
        int a,b;
        a = U1.root(i);
        b = U2.root(i);
        PII p = MP(a,b);
        f[p]++;
    }

    FORq(i,1,N){
        int a,b;
        a = U1.root(i);
        b = U2.root(i);
        PII p = MP(a,b);
        printf("%d ",f[p]);
    }
    printf("\n");
}