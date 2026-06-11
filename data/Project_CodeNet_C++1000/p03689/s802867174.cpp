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

const int MAX = 100 * 1000 + 47;

int main()
{
    // freopen("in.txt", "r", stdin);
    int n, m, nn, mm;
    cin >> n >> m >> nn >> mm;
    
    if (n % nn == 0 && m % mm == 0)
    {
        cout << "No" << endl;
        return 0;
    }
    
    cout << "Yes" << endl;
    int pos = 1111;
    int neg =  - (nn * mm - 1) * pos - 1;

    
    FOR(i, 0, n)
    {
        FOR(j, 0, m)
        {
            if (i % nn == nn -1 && j % mm == mm -1)cout << neg << " ";
            else cout << pos << " ";
        }
        cout << endl;
    }
    
    
    
    

    
    return 0;
}



