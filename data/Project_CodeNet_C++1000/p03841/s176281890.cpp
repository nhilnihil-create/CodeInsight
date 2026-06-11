// LNU_Algotesters
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <ctime>
#include <fstream>
#include <complex>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MAX = 555;
const int MOD = INF;


int X[MAX];
int L[MAX];
int G[MAX];
int U[MAX];
int ANS[MAX * MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    FOR(i, 1, n+1)cin >> X[i];
    
    FOR(i, 1, n * n + 1)
    {
        bool fnd = 0;
        FOR(j, 1, n+1)
        {
            if (X[j] == i)
            {
                ANS[i] = j;
                fnd = 1;
                break;
            }
        }
        if (fnd)continue;
        int bst = -1;
        FOR(j, 1, n + 1)
        {
            if (i < X[j] && L[j] != j-1)
            {
                if (bst == -1 || X[j] < X[bst])
                    bst = j;
            }
        }
      //  cout << bst << endl;
        if (bst != -1)
        {
            ANS[i] = bst;
            L[bst]++;
            continue;
        }
        bst = -1;
        FOR(j, 1, n+1)
        {
            if (i > X[j] && G[j] != n - j)
            {
                if (bst == -1 || X[j] > X[bst])
                    bst = j;
            }
        }
        if (bst != -1)
        {
            G[bst]++;
            ANS[i] = bst;
            continue;
        }
        cout << "No" << endl;
        return 0;
        
    }
    cout << "Yes" << endl;
    FOR(i, 1, n*n+1)
    cout << ANS[i] << " ";
 
    
    
}


