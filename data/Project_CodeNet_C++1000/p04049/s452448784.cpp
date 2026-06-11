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

vi adjList[2000];
int dist[2000];
queue<int> Q;
int main() {
    int i;
    int N,K,A,B;
    scanf("%d %d",&N,&K);
    for (i = 0; i < N-1; i++) {
        scanf("%d %d",&A,&B);
        A--,B--;
        adjList[A].pb(B);
        adjList[B].pb(A);
    }

    int j,k,ans = N;
    if (K & 1) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < adjList[i].size(); j++) {
                int x = adjList[i][j];
                if (x < i) {
                    fill(dist,dist+N,-1);
                    dist[i] = 0,Q.push(i);
                    dist[x] = 0,Q.push(x);
                    while (!Q.empty()) {
                        int u = Q.front();
                        Q.pop();

                        for (k = 0; k < adjList[u].size(); k++) {
                            int v = adjList[u][k];
                            if (dist[v] == -1) dist[v] = dist[u]+1,Q.push(v);
                        }
                    }
                    int c = 0;
                    for (k = 0; k < N; k++) {
                        if (dist[k] > K/2) c++;
                    }
                    ans = min(ans,c);
                }
            }
        }
    }
    else {
        for (i = 0; i < N; i++) {
            fill(dist,dist+N,-1);
            dist[i] = 0,Q.push(i);
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();

                for (j = 0; j < adjList[u].size(); j++) {
                    int v = adjList[u][j];
                    if (dist[v] == -1) dist[v] = dist[u]+1,Q.push(v);
                }
            }
            int c = 0;
            for (j = 0; j < N; j++) {
                if (dist[j] > K/2) c++;
            }
            ans = min(ans,c);
        }
    }
    printf("%d\n",ans);

    return 0;
}

