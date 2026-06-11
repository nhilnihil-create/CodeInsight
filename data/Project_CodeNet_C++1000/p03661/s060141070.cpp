#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll A[n + 1];
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        A[i] = sum;
    }
    ll ans = 1LL<<50;
    for(int i = 0; i < n - 1; i++)
    {
        ll tmp = sum - A[i];
        ans = min(abs(A[i] - tmp), ans);
    }
    cout << ans << "\n";
    return 0;
}

