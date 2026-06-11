#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

int a[2000];
int dp[2000][2000];
int main() {
    int i;
    int N,x;
    scanf("%d %d",&N,&x);
    for (i = 0; i < N; i++) scanf("%d",&a[i]);

    int j;
    LLI ans = 1e18;
    for (i = 0; i < N; i++) {
        dp[i][i] = a[i];
        for (j = i+1; j < N; j++) dp[i][j] = min(dp[i][j-1],a[j]);
    }
    for (i = 0; i < N; i++) {
        LLI sum = (LLI) i*x;
        for (j = 0; j < N; j++) {
            if (j-i < 0) sum += min(dp[0][j],dp[j-i+N][N-1]);
            else sum += dp[j-i][j];
        }
        ans = min(ans,sum);
    }
    printf("%lld\n",ans);

    return 0;
}

