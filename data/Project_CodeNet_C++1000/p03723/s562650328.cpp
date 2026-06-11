#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

ll ans;
ll A, B, C;
bool flag;
void solve(ll a, ll b, ll c, ll count);

int main()
{
    cin >> A >> B >> C;
    ans = 0;
    flag = true;
    solve(A, B, C, 0);
    if (flag)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

void solve(ll a, ll b, ll c, ll count)
{
    if (a == A && b == B && c == C && count != 0)
    {
        flag = false;
        return;
    }
    else if ((a % 2) + (b % 2) + (c % 2))
    {
        return;
    }
    ans++;
    solve((b + c) / 2, (c + a) / 2, (a + b) / 2, count + 1);
    return;
}