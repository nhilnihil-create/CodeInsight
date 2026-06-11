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


void solve(long long N, std::vector<long long> p){
    LL max_a = 1e9;
    LL step = max_a / N;
    VLL b_list(N, 0);
    REP(i, N) {
        cout << (step * (i+1)) << (i+1 == N ? "\n" : " ");
        b_list[i] += step * (N-i-1);
        b_list[p[i]-1] += i+1;
    }

    REP(i, N) {
        cout << b_list[i] << (i+1 == N ? "\n" : " ");
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> p(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&p[i]);
    }
    solve(N, std::move(p));
    return 0;
}
