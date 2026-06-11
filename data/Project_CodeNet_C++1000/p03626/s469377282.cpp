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

const LL MOD = 1000000007;

void solve(long long N, std::vector<std::string> S){
    LL ans = S[0][0] == S[1][0] ? 3 : 6;
    int idx = S[0][0] == S[1][0] ? 1 : 2;
    bool prevI = S[0][0] == S[1][0];
    while(idx<N){
        if(S[0][idx] == S[1][idx]) {
            if(prevI) ans *= 2;
            idx++;
            prevI = true;
        } else {
            if(prevI) ans *= 2;
            else ans *= 3;
            idx += 2;
            prevI = false;
        }

        ans %= MOD;
    }

    cout << ans << endl;
}

// rg rg rb
// gr gb gr

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<std::string> S(2);
    for(int i = 0 ; i < 2 ; i++){
        std::cin >> S[i];
    }
    solve(N, std::move(S));
    return 0;
}
