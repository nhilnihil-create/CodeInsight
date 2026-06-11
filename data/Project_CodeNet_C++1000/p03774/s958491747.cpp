#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define ALL(x)      (x).begin(),(x).end()
#define REP(i,n)    for(int i=0;i<(n);i++)
#define REP1(i,n)   for(int i=1;i<(n);i++)
#define REP2(i,d,n) for(int i=(d);i<(n);i++)
#define RREP(i,n)   for(int i=(n);i>=0;i--)
#define CLR(a)      memset((a),0,sizeof(a))
#define MCLR(a)     memset((a),-1,sizeof(a))
#define RANGE(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};


void solve(long long N, long long M, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c, std::vector<long long> d){
    REP(i, N) {
        LL min_idx = -1;
        LL min_cost = INFL;

        REP(j, M) {
            LL cost = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if (cost < min_cost) {
                min_idx = j+1;
                min_cost = cost;
            }
        }

        cout << min_idx << endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> a(N);
    std::vector<long long> b(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    std::vector<long long> c(M);
    std::vector<long long> d(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&c[i]);
        scanf("%lld",&d[i]);
    }
    solve(N, M, std::move(a), std::move(b), std::move(c), std::move(d));
    return 0;
}
