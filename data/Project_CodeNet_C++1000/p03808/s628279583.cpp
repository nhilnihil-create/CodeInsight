#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define REPr(i,n) for(int i=(n)-1;i>=0; --i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
#define FORqr(i, m , n) for(int i = (n);i >=(m);--i)
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
#define VSCD(v,N) REP(i,N){int (x); SCD(x); v.PB(x);}
#define VSCLLD(v,N) REP(i,N){long long (x); SCLLD(x); v.PB(x);}
#define PRINTD(n) printf("%d\n",n)
#define PRINTLLD(n) printf("%lld\n",n)
#define DEBUG printf("%s\n","debug")
#define fst first
#define snd second
#define SIN(x,S) (S.count(x) != 0)
#define M0(x) memset(x,0,sizeof(x))
#define FILL(x,y) memset(x,y,sizeof(x))
#define MM(x) memset(x,-1,sizeof(x))
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> PII;
typedef pair<long long,long long> PLL;
typedef vector<int> VI;
typedef vector < VI > VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
////////////////////////////////////////////////////////////////////
const ll MOD = 1000000007;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
////////////////////////////////////////////////////////////////////
int main(){
    ll N,K;
    cin >> N;
    vector<ll> A;
    ll sum = 0;
    VSCLLD(A,N);
    REP(i,N){
        sum += A[i];
    }

    A.PB(A[0]);

    vector<ll> D;
    bool flg = true;
    REP(i,N){
        D.PB(A[i+1] - A[i]);
    }
    if ((2 * sum) % (N * (N+1)) != 0) flg = false;
    K = 2 * sum / (N * (N+1));

    REP(i,N){
        D[i] -= K;
        if (D[i] > 0) flg = false;
        if (D[i] % N != 0) flg = false;
    }

    if (flg) printf("YES\n");
    else printf("NO\n");


}
