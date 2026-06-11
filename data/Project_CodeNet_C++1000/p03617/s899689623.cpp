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


void solve(long long Q, long long H, long long S, long long D, long long N){
    vector<pair<LL, int>> memo;
    memo.PB(MP(Q*8, 1));
    memo.PB(MP(H*4, 2));
    memo.PB(MP(S*2, 3));
    memo.PB(MP(D, 4));

    sort(ALL(memo));

    LL ans = 0;
    int idx = 0;
    if(memo[0].second == 4) {
        ans += N / 2 * memo[0].first;
        N = N % 2;
        idx++;
    }

    ans += memo[idx].first / 2 * N;
    cout << ans << endl;
}

int main(){
    long long Q;
    scanf("%lld",&Q);
    long long H;
    scanf("%lld",&H);
    long long S;
    scanf("%lld",&S);
    long long D;
    scanf("%lld",&D);
    long long N;
    scanf("%lld",&N);
    solve(Q, H, S, D, N);
    return 0;
}
