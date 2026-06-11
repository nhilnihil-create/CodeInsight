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

int A[MAX];

int main()
{
   
    int n;
    scanf("%d", &n);
    FOR(i, 0,n)
    scanf("%d", A + i);
    
    
    sort(A, A + n);
    reverse(A, A + n);
    
    int x = 0, y = 0;
    
    while(true)
    {
        if (y + 1 == n)break;
        if (x + 1 >= A[y + 1])break;
        x++, y++;
    }
    
   // cout << x << " " << y << endl;
    
    int a = A[y] - x - 1, b = 0;
    while(A[y+1] > x)b++, y++;
    
  //  cout << a << " " << b << endl;
    if ((a & 1) == 0 && (b & 1) == 0)
        cout << "Second" << endl;
    else
        cout << "First" << endl;
    
}
