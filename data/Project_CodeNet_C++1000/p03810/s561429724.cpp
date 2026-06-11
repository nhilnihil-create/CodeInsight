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

#define F(i, n) for(int i = 0; i < n; ++i)
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

const int MAX = 200*1000+47;

LL A[MAX];
int n;

int gcd(int a, int b)
{
    if (!b)return a;
    return gcd(b, a%b);
}

bool win()
{
    int e = 0, o = 0;
    FOR(i, 0, n)
        if (A[i] & 1)o++;
        else e++;
    if (e & 1)return 1;
    if (o > 1)return 0;
    if (n == 1)return 0;
    
    FOR(i, 0, n)
    {
        if ((A[i] & 1) == 0)continue;
        if (A[i] == 1)return 0;
        A[i]--;
    }
    int g = 0;
    FOR(i, 0, n)g = gcd(g, A[i]);
    FOR(i, 0, n)A[i] /= g;
    return !win();
    
}

int main()
{
    scanf("%d", &n);
    int a = 0, b = 0;
    FOR(i, 0, n)
        scanf("%d", A + i);
    if (win())
        printf("First");
    else
        printf("Second");
    
    return 0;
}









