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


void solve(long long n, std::vector<long long> a){
    LL ans1 = (a[0] == 0 ? 1 : 0), ans2 = abs(a[0]) + 1;
    LL tmp1 = (a[0] == 0 ? 1 : a[0]), tmp2 = (a[0] < 0 ? 1 : -1);
    REP1(i, n) {
        if(tmp1 < 0) {
            tmp1 += a[i];
            if (tmp1 <= 0) {
                ans1 += abs(tmp1) + 1;
                tmp1 = 1;
            }
        } else {
            tmp1 += a[i];
            if(0 <= tmp1) {
                ans1 += tmp1 + 1;
                tmp1 = -1;
            }
        }

        if(tmp2 < 0) {
            tmp2 += a[i];
            if (tmp2 <= 0) {
                ans2 += abs(tmp2) + 1;
                tmp2 = 1;
            }
        } else {
            tmp2 += a[i];
            if(0 <= tmp2) {
                ans2 += tmp2 + 1;
                tmp2 = -1;
            }
        }
    }

    cout << min(ans1, ans2) << endl;
}

int main(){
    long long n;
    scanf("%lld",&n);
    std::vector<long long> a(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%lld",&a[i]);
    }
    solve(n, std::move(a));
    return 0;
}
