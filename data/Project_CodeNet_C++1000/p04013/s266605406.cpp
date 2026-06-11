#include <iostream>
#include <cstdio>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
//#include <unordered_map>
using namespace std;
#define dbg(x) cerr << #x " = " << x << endl;
typedef pair<int, int> P;
typedef long long ll;
const int MAXN = 55;
ll a[MAXN];
ll dp[55][55*55];
int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, A;
    cin >> n >> A;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j > 0; j--)
        {
            for(int k = A * n; k >= a[i]; k--)
            {
                dp[j][k] += dp[j - 1][k - a[i]];
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += dp[i][i *A];
    }
    cout << ans << endl;
    

}