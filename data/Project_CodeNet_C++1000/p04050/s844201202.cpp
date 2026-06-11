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

#define FOR(i,a,b) for(int i = (a); i <(b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a,value, sizeof(a))

#define ALL(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<LL> VI;
typedef pair<int, LL> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX = 100 * 2 + 7;

int A[MAX];



int main()
{
    //cout << f(2, 1) << endl;
    //freopen("input.txt", "r", stdin);
    //ios::sync_with_stdio(false);cin.tie(NULL);
  
    int  n, m;
    scanf("%d%d", &n, &m);
    FOR(i, 0, m)
        scanf("%d", A + i);
    sort(A, A + m);
    reverse(A, A + m);
    
    if( m == 1)
    {
        cout << A[0] << endl;
        if (n == 1)
        {
            cout << 1 << endl << 1 << endl;
        }
        else
        {
            cout << 2 << endl << n-1 << " " << 1 << endl;
        }
        return 0;
    }
    VI X[2];
    FOR(i, 0, m)
        X[A[i] & 1].PB(A[i]);
    
    if (SZ(X[1]) > 2)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    
    VI RES;
    if (SZ(X[1]))
        RES.PB(X[1][0]);
    
    FOR(i, 0, SZ(X[0]))
        RES.PB(X[0][i]);
    
    if (SZ(X[1]) > 1)
        RES.PB(X[1][1]);
    
    FOR(i, 0, SZ(RES))
    {
        cout << RES[i] << " ";
    }
    cout << endl;
    
    RES[0]--;
    RES[SZ(RES)-1]++;
    int idx = 0;
    if (RES[idx] == 0)idx++;
    cout << SZ(RES)-idx << endl;
    FOR(i, idx, SZ(RES))
    cout << RES[i] << " ";
    cout << endl;
    
    
    
    return 0;
}
