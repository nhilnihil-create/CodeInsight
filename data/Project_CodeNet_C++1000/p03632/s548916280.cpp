#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define INF 100000000000
#define MOD 100000007 //10^9+7
using namespace std;
using ll = long long;
using P = pair<int, int>;

char s[50][50];
int h, w;

int main()
{
    int n, m, k, i, j;
    int a, b, c, d;
    cin >> a >> b >> c >>d;
    
    const int lower = max(a,c);
    const int upper = min(b,d);

    cout << max(0, upper - lower) << endl;    

    return 0;
}
