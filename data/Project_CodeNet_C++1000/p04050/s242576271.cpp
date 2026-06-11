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

int A[100];
int main() {
    int i;
    int N,M;
    scanf("%d %d",&N,&M);
    for (i = 0; i < M; i++) scanf("%d",&A[i]);

    int c = 0;
    for (i = 0; i < M; i++) {
        if (A[i] & 1) c++;
    }
    if (c > 2) printf("Impossible\n");
    else {
        for (i = 1; i < M-1; i++) {
            if (A[i] & 1) {
                if (A[0] & 1) swap(A[M-1],A[i]);
                else swap(A[0],A[i]);
            }
        }
        for (i = 0; i < M; i++) printf("%d ",A[i]);
        if (M == 1) {
            if (N == 1) printf("\n1\n1\n");
            else printf("\n2\n%d 1\n",N-1);
        }
        else {
            printf("\n%d\n",(A[M-1] == 1) ? M-1:M);
            for (i = 0; i < M; i++) {
                if (i == 0) printf("%d ",A[i]+1);
                else if (i == M-1) {
                    if (A[i] > 1) printf("%d ",A[i]-1);
                }
                else printf("%d ",A[i]);
            }
            printf("\n");
        }
    }

    return 0;
}

